<!-- 🔗 Custom Stylesheet -->
<link rel="stylesheet" href="../../../_css/main.css">

<!-- 🖼️ Site Logo -->
![Site Logo](/_pix/logos/logo-ehw-kb-h32.png)

# NOTES: Week 1 (CIS 171 - Linux I)

---


# 🎬 Linux 1 Introduction.mp4

- Cisco Network Acadmy
- Will earn a **badge** in Linux

- Start with "Start Here"


- Exam 2 will be honor lock
- It will be part multiple choice and part coding


### Module 1

- We'll do about 1 module a week


- Form study groups with classmates

- She tries to embed certifications in all her courses

- Linkedin
- Google
- Virtual Machines

- Communicate with her via emails in the "INBOX"

### LinkedIn links

- If you have a LinkedIn profile already

- Tell the AI to "summarize" your professional summary

- [ ] Follow **Cisco Networking Academy**

- [ ] Attendance Quiz
- [ ] Introduction
- [ ] Create / Update LinkedIn account

- [ ] Linux Cisco Course - NDG Linux Unhatched read course content

---


# 🎬 Linux in 100 Seconds.mp4

- Linux is open sourdce operating system
- Created 1991 by Linus Torvalds, who wanted to create a free MINIX
- Linux used everywhere: eg: web servers, embedded apps like smart tv, mobile devices running android, best choice for personal computer
- Many distros (distributions): Eg, debian, arch, fedora

- OS manages memory and CPU processes

- Bootloader puts the system into memory
- Kernel is seed from which rest of OS grows
- Process scheduler, device drivers, memory manager
- Exposed via system call interfaced, wrapped in GNU C standard library, providing API that user apps can interact with

- USERSPACE: apps that make the os usable for humans like shell, windowing desktop gui, developing utils, etc
- Users home directory

---

### List of Common Linux Distros

- Arch Linux
- Debian
- Fedora
- [Foresight Linux](https://en.wikipedia.org/wiki/Foresight_Linux) (#GOTCHA: Looked like it said "breslight" in the low res badge image)
- Gentoo Linux
- Mandriva
- Linux Mint
- Kubuntu
- openSuse
- PCLinuxOS
- redHat
- sabayon
- slackware
- slax
- ubuntu
- xubuntu

---

### Commands & Vocab

**`root@linux-machine`**

: `user@host`; format for the default console prompt

**`~`**

: user's home directory representation in the terminal

**`pwd`**

: Print working directory - shows the full directory path in console

**`cd`**

: change directory
- `cd ~`: Go home
- `cd ..`: go back one directory, to parent level

**`ls`**

: list files in current directory

**`touch`**

: create a file


**vi**

: text editor; others include vim, nano, emacs, etc.

---

#### VIM Workflow

- `i`: insert text
- `esc` > `:wq`: write to file system


---

- `cat`: read a file out to console
- `grep`: search in a file
- `du`: find out how large in bytes the file is; ex, `du -h filename.txt`
- `chown`: change owner of a file or folder; ex: `chown jeff screenplay.txt`
- `sudo`: run with admin permssions; ex: `sudo tail screenplay.txt`

- **package manager**: an application that manages the installation of command line applications; ex: apt, brew, etc

- **`apt-get install`**: installs a program with apt; ex: `sudo apt-get install sl`
- **`history`**: show previous commands list










































