<!-- Custom stylesheet -->
<link rel="stylesheet" href="../../_css/main.css">

<!-- Site logo -->
![Site Logo](/_pix/logos/logo-ehw-kb-h32.png)

> [🏚️ README](../../../README.md) | [📁 Courses](../../index.md) | [📚 Vocabulary](../../Vocabulary.md) | [🗓️ Assignments Schedule](../Assignments_Schedule.md) | [🔖 Bookmark](#bookmark)


# CIS 171 - Linux I:  <br> NOTES: Week 2 - IT Support Fundamentals (Aug 24 - 31)

## ⭐ **This week, you will:**

- N/A

- - -


> The following are my notes on the **CompTIA: Linux+ CertMaster Perform** V8 learning platform course

## 📖 1.1 - Use Linux Basics

Working with Linux begins with an understanding of the command line. Linux servers are primarily managed from the command line, using shells such as Bash. Bash enforces a particular syntax or way of structuring commands. In addition, Linux holds its configurations in text files, so it's critical that sysadmins can edit these files to manage system settings. Man pages are available as quick reference documents to help administrators recall the function of specific commands and any available options.

> - 📌 #TIP: Bash is a common command line shell used to manage Linux machines

> - **man page:** Quick reference docs to help admins understand the purpose, available options, and syntax of a command

Misconfigurations or physical failures may provide troubleshooting opportunities, so sysadmins should follow a **standard methodology** to help **narrow the scope** of problems, **solve the root cause** of the issue, and **manage documentation** related to configuration issues.

**Exam Objectives**

*   1.1.2 Linux concepts > **Filesystem Hierarchy Standard**
*   1.1.3 Linux concepts > **Server architectures**
*   1.1.4 Linux concepts > **Distributions**
*   1.1.5 Linux concepts > **GUI**
*   1.5.1 Shell operations > **Common environmental variables**
*   1.5.5 Shell operations > **Basic Shell Utilities**
*   2.1.1 Manage file system > **Utilities**
*   2.2.6 Manage local accounts > **List**
*   4.2.10 Shell Scripting > **Variables**
*   5.2.1 Troubleshoot Linux > **Common issues**

### 🟣 1.1.1 Linux Distributions


**Operating systems** are layers between computer hardware and user programs, like web browsers or word processors. Operating systems provide an environment for these programs to run and enable users to manage computer components, like turning off a web camera or printing documents. Microsoft Windows, Apple macOS, and Linux are the three most common operating systems.

> - **operating system:** Software that facilitates the control and configuration of the computer device via device drivers, services, and one or more user interfaces.

Linux is unique among these three because it is **open-source**. The source code that makes up the operating system is available to anyone at no cost. Any person can change the Linux source code to customize the operating system. Most people will never do this, but the possibility exists. Windows and macOS are **closed-source** or **proprietary**, meaning they don't expose the operating system's programming code and don't allow anyone else to modify it.

> - **open-source**: Licensing model that grants permissive rights to end-users, such as to install, use, modify, and distribute a software product and its source code, as long as redistribution permits the same rights.

> - **proprietary:** Software code or security research that remains in the ownership of the developer and may only be used under permitted licence conditions; closed-source

Linux is a powerful and flexible operating system, so it is commonly used on **servers** to support massive amounts of email traffic, web browsing, file storage, and more. Almost all cloud computing platforms employ Linux, making it a very common choice for high-tech environments. Linux is a useful desktop operating system for day-to-day use, too. It can be an excellent option for home users, business professionals, and developers.

> - **server:** A server provides shared resources on the network and allows clients to access this information. The advantage of a server-based system is that resources can be administered and secured centrally. Servers must be kept secure by careful configuration (running only necessary services) and maintenance (OS and application updates, malware/intrusion detection, and so on). Where a network is connected to the Internet, servers storing private information or running local network services should be protected by firewalls so as not to be accessible from the Internet.

Because anyone can create and release their own version of Linux, there are thousands of different options. These individual releases are called distributions (or "**distro**" for short). Distributions are purpose-specific versions of Linux that address a specific need, such as system security or application hosting.

> - **distro:** One of several fully functional operating systems and members of the Linux family that run the Linux kernel, GNU software, and additional components; distribution

Many distributions trace their history back to one of two specific Linux distributions: **Red Hat Linux** or **Debian Linux**. One of the main differences between these two distros is how they manage software. The distros derived from Red Hat Linux use different software managers than those derived from Debian Linux. The software is also packaged differently.

Some of the most common distros include:

*   Fedora Linux
*   Ubuntu Desktop, Server, Core
*   Red Hat Enterprise Linux (RHEL)
*   Rocky Linux
*   AlmaLinux
*   Linux Mint
*   Debian
*   openSUSE

Figure 1. Linux Release Timeline![A horizontal timeline shows the evolution of several operating systems.](../../../_pix/comptia-linux+__05_linux-release-timeline.png)

> **🏷️ Image Description**:  After the release of Linux in 1991, the two major branches, Debian and Red Hat, followed quickly and generated hundreds of distros.

Many of these distributions fulfill specific roles in the marketplace, including desktop or workstation computers, servers, IoT devices, mobile devices, or other functions. While mobile and **IoT** implementations are common, **the focus of this course is on server deployments**. One of the most important characteristics of a distribution is its included software.

> - 📌 #TIP: This course focuses on *Linux for SERVER DEPLOYMENTS*

> - **IoT:** internet of things; Devices that can report state and configuration data and be remotely managed over IP networks.

Some Linux distributions contain **end-user applications**, such as word processors or presentation software. Others contain server services, such as web services or file storage. Still other distributions include security software or creative applications, such as music editing.

Linux server deployments are put to use in the following ways:

*   **Webserver:** Hosts one or more websites.
*   **Name resolution:** Hosts Domain Name System (DNS) name resolution services.
*   **File:** Stores business data, usually in some form of text document.
*   **Print:** Manages the print process and access to print services.
*   **Log:** Centralizes and stores log files from other systems.
*   **Virtualization/container:** Hosts virtual machine or container virtualization software.
*   **Database:** Hosts one or more databases.
*   **Cluster:** Works with other cluster nodes to host high-performance, fault-tolerant services.


> - **DNS:** domain name system; Service that maps fully qualified domain name labels to IP addresses on most TCP/IP networks, including the Internet. Also known as "DNS."

> - **virtual machine:** Guest operating system installed on a host computer using virtualization software (a hypervisor), such as Microsoft Hyper-V or VMware. Also known as a "VM."

> - **container:** Type of virtualization applied by a host operating system to provision an isolated execution environment for an application.

> - **DevOps:** A combination of software development and systems operations, and refers to the practice of integrating one discipline with the other.

> - **DevSecOps:** A combination of software development, security operations, and systems operations, and refers to the practice of integrating each discipline with the others.


**Linux is heavily involved in modern infrastructure management.** A **DevOps** approach to the management of such Linux servers and services works toward high quality, iterative, and frequent updates and releases. Linux tends to include security in design and implementation throughout the development lifecycle. This approach is sometimes called **DevSecOps**.

> - 📌 #TIP: Most commands are consistent across distributions. A few commands, such as those for software management, may be specific to one group of distributions or another. For example, Red Hat Linux uses the `rpm`, `yum`, and `dnf` commands to manage software, while Debian Linux uses `dpkg` and `apt` or `aptitude`.


---


### 🟣 1.1.2 Linux Interfaces


One distinguishing characteristic of Linux compared to other operating systems is its reliance on the **command-line interface (CLI)**. Linux administrators frequently use the CLI for everyday tasks, while administrators of other platforms often use graphical user interface (GUI) utilities. The installation of a GUI is often optional with Linux and may be frowned upon for performance and security reasons.

> - **CLI:** command-line interface; A text-based interface between the user and the operating system that accepts input in the form of commands

> - **GUI:** graphical user interface; A text-based interface between the user and the operating system that accepts input in the form of commands

> - ⚠️ #GOTCHA: Avoid installing GUIs on Linux servers because they tax hardware resources like memory and processor time

A GUI consumes a great many hardware resources, specifically memory and processor time. Desktop systems might need a user-friendly GUI but **servers usually do not**. On a server, these hardware resources should be dedicated to the service provided, such as handling database queries or managing print jobs.

The CLI has these characteristics:

*   **Speed:** It’s usually quicker to execute a series of commands at the CLI (assuming you know the commands).
*   **Performance:** CLI environments consume fewer hardware resources, leaving those resources free to support the server’s purpose.
*   **Scriptability:** You can write CLI commands to a text file, which the system then reads and executes in a consistent, efficient, repeatable, and scheduled manner. This is called scripting.
*   **Nonintuitive:** Commands are often difficult to relate to or understand, with no apparent logic.
*   **Inconsistent:** Many commands differ from each other in small but distinctive ways, making it difficult to recall exactly how to use them.

## Common Command-line Interfaces

Command-line interfaces are available in Linux, Windows, and macOS. Users in a CLI type commands using a specific syntax, and the system processes the commands. At first, this input may seem intimidating or difficult, but CLI environments get easier with use. **These environments are usually faster and offer automation options that are not available in GUIs.**

Figure 1. Command Examples

![A screenshot of a Linux terminal window shows output for three commands.](https://cdn.testout.com/linux-plus-xk0-006-en-us/materials/resources/text/s_use_linux_basics/1782-1636742454721-demo-agif__1_.gif)

> **🏷️ Image Description**: Several sample commands and their output, including `whoami`, `pwd`, and `date`.

## Common Graphical User Interfaces

Just as there are many different Linux distros, there are also many different Linux graphical environments. Windows and macOS users have one GUI available to them—whatever graphical environment Microsoft and Apple choose to provide. Linux users have the freedom to install zero, one, or many GUI environments and switch between them.

> - 📌 #TIP: Linux users can install multiple GUIs and switch between them at will!

These GUIs are usually distinguished by two characteristics: **user-friendly interface and performance**. Some users like the look and feel of a particular GUI over others. In addition, some GUIs consume more processor time and memory than others do. Luckily, many options are available in the Linux world.

Common GUI environments include **GNOME**, KDE Plasma, Cinnamon, and MATE.

> - **GNOME:** The default desktop environment for most Linux distributions that run the X Window System or Wayland.

Figure 2. GUI Example

![A screenshot shows three application windows.](https://cdn.testout.com/linux-plus-xk0-006-en-us/materials/resources/text/s_use_linux_basics/2451-1642094340933-UbuntuDesktop.png)

> **🏷️ Image Description**: An Ubuntu GUI with running apps and menus.


#BUSINESS_NEEDS

Another important attribute of Linux GUIs is support for **graphics-based applications**, such as **web browsers**, **presentation software** (eg, MS PowerPoint), and **image-editing programs** (eg, Adobe Photoshop). These types of software are critical to today's business environments and users.

Linux graphical interfaces provide many accessibility features that are worth exploring. Some of these include **high-contrast displays**, screen readers, **magnifiers**, visual alerts, and **keyboard sticky keys**.


---

### 🟣 1.1.3 Command Shells

A software component called a **shell** provides the command-line interface (CLI). The shell accepts user input, processes the input for syntax, and provides output back to the user. The default shell for most Linux distributions is **bash**, and this is the shell that sysadmins should be prepared to work with.

> - **shell:** System component providing a command interpreter by which the user can use a kernel interface and operate the OS.

> - **bash:** Command interpreter and scripting language for Unix-like systems.

Other common Linux shells include ksh, or **KornShell**, which is common among Unix servers; **Zsh**, or Z Shell, with quite powerful scripting capabilities; and **Fish**, or friendly interactive shell, an interface that provides a user-friendly experience and web-based configurations.

By way of comparison, Windows Server also uses shells: the traditional, DOS-like cmd.exe shell and Microsoft PowerShell. The current (at the time of this writing) default shell for macOS is the Zsh.

> - 📌 #TIP: Bash is the Linux default and the only shell to concern yourself with for CompTIA Linux+.

---








































