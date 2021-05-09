from collections import namedtuple

Declaration = namedtuple('Declaration', ['name', 'version', 'docstring', 'args', 'raw_name'])
Argument = namedtuple('Argument', ['name', 'type', 'default', 'index'])
Module = namedtuple('Module', ['shapes', 'aliases'])
Alias = namedtuple('Alias', ['name', 'target'])

def parse_arg(index, arg):
    ''' Parses a single argument, returning an Argument
    '''
    *type, name = arg.split(' ')
    type = ' '.join(type)
    default = None
    if '__' in name:
        default = name.split('__')[1]
    name = name.split('__')[0]
    return Argument(name=name, type=type, default=default, index=index)

def parse_decl(line, f):
    ''' Parses a single declaration, returning a Declaration

        This function continues to read lines from f if the declaration
        spans multiple lines.
    '''
    _, name = line.split(' ', 1)
    name, rest = name.split('(', 1)
    if '__' in name:
        name, version = name.split('__')
    else:
        version = None

    raw_name = name
    name = name[11:]

    doc = ''
    if rest.endswith(');'): # single-line form
        args = [parse_arg(i, s.strip()) for i, s in enumerate(rest.strip(');').split(','))]
    else:
        args = []
        start = 0
        while True:
            line = f.readline().strip()
            if line.startswith('// '):
                doc += line[3:] + '\n'
            else:
                args += [parse_arg(i + start, s.strip()) for i, s in
                         enumerate(line.strip(');').split(',')) if s]
                start += len(line.strip(');').split(','))

            if line.endswith(');'):
                break

    if any([a.name == name for a in args]):
        raise RuntimeError("Argument shadows function name in '%s'" % name)

    return Declaration(name=name, version=version, docstring=doc[:-1],
                       args=args, raw_name=raw_name)


def parse_alias(s):
    ''' Parses a declaration of the form LIBFIVE_ALIAS(name, target)
    '''
    name, target = s.split('(')[1].split(')')[0].split(',')
    return Alias(name=name.strip(), target=target.strip())


def parse_section(s):
    ''' Parses a declaration of the form LIBFIVE_SECTION(name)
    '''
    return s.split('(')[1].split(')')[0].strip()


def parse(f):
    ''' Parses stdlib.h, based on idiosyncratic conventions

        This is a terrible parser and won't work for any other C header file
    '''
    section = None;
    modules = {}
    while True:
        line = f.readline()
        if line == '':
            break
        line = line.strip()
        if line.startswith('LIBFIVE_SECTION'):
            section = parse_section(line)
            modules[section] = Module(shapes=[], aliases=[])
        elif line.startswith('LIBFIVE_STDLIB'):
            modules[section].shapes.append(parse_decl(line, f))
        elif line.startswith('LIBFIVE_ALIAS'):
            modules[section].aliases.append(parse_alias(line))
    return modules

def parse_stdlib():
    with open('stdlib.h', 'r') as f:
        return parse(f)

if __name__ == '__main__':
    print(parse_stdlib())
