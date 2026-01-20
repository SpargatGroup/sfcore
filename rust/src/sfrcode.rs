use std::os::raw::{c_char, c_int};
unsafe extern "C" {
    pub fn sfencrypt(input: *const c_char, output: *mut c_char, key: c_int);
    pub fn sfdecrypt(input: *const c_char, output: *mut c_char, key: c_int);
}