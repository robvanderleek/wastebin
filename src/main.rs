use std::env;
use std::fs;
use std::path::Path;

fn usage() {
    println!("A wastebin for your shell");
    println!("Usage:");
    println!("  wb <path1> <path2> ... <pathN>");
    println!();
    println!("path: paths to move to wastebin");
    println!("--version: print version");
}

fn main() {
    let args: Vec<String> = env::args().collect();
    if args.len() <= 1 {
        usage();
        return;
    }
    if args[1] == "--version" {
        let version = option_env!("CARGO_PKG_VERSION").unwrap_or("unknown");
        println!("wastebin version {version}");
        return;
    }
    let wastebin_dir = env::home_dir()
        .expect("Could not find home directory")
        .join("wastebin");
    for arg in &args[1..] {
        let result = fs::exists(arg).unwrap();
        if result {
            let path = Path::new(arg);
            if path.is_file() {
                let file_name = path.file_name().unwrap();
                fs::rename(path, wastebin_dir.join(file_name)).expect("Could not move file");
                println!("Moved file {} to wastebin.", arg);
            }
        } else {
            println!("File {} does not exist.", arg);
        }
    }
}
