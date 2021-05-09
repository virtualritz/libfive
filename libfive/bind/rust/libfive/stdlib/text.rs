
/// # Text <a name="text"></a>
impl Tree {
    pub fn text(txt: impl Into<Vec<u8>>, pos: TreeVec2) -> Self {
        let txt = std::ffi::CString::new(handle).unwrap();
        Self(unsafe { sys::libfivestd_text(txt.as_ptr(), sys::tvec2 { x: pos.x.0, y: pos.y.0 }) })
    }
}
