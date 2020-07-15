use std::thread;

fn main() {
    let t = thread::spawn(move || {
        println!("Hello, thread!");
    });

    let _res = t.join();
}
