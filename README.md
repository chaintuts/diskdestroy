## General
____________

### Author
* Josh McIntyre

### Website
* jmcintyre.net

### Overview
* DiskDestroy is a simple data destruction program for storage media

## Development
________________

### Git Workflow
* master for releases (merge development)
* development for bugfixes and new features

### Building
* make build
Build the utility
* make clean
Clean the build directory

### Features
* Take the low-level disk file (such as /dev/sdb)
* Ask for user confirmation before any data is overwritten
* Zero-fill the entire disk (thus rendering data unrecoverable)
* WARNING: This program will render any data on a drive PERMANENTLY UNRECOVERABLE! Use with care.

### Requirements
* Requires a terminal emulator

### Platforms
* Linux
* MacOSX

## Usage
____________

### CLI Usage
* Run `./diskdestroy <disk path>` to destroy data on the specified disk
* Ex: `./diskdestroy /dev/sdb`
* The program will ask for user confirmation before any data is overwritten
