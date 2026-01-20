use std::os::raw::{c_char, c_int};
unsafe extern "C" {
    pub fn sfswap(a: *mut i32, b: *mut i32);
}