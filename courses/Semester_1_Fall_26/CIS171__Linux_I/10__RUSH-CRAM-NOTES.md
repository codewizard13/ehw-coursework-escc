<!-- Custom stylesheet -->
<link rel="stylesheet" href="../../_css/main.css">

<!-- Site logo -->
![Site Logo](/_pix/logos/logo-ehw-kb-h32.png)

> [🏚️ README](../../../README.md) | [📁 Courses](../../index.md) | [📚 Vocabulary](../../Vocabulary.md) | [🗓️ Assignments Schedule](../Assignments_Schedule.md) | [🔖 Bookmark](#bookmark)


# CIS 171 - Linux I:  <br> NOTES: 

> The following are my notes on the **CompTIA: Linux+ CertMaster Perform** V8 learning platform course
> The represent sparse notes thrown together, not perfectly organizized while cramming to complete assignments
> It seems it will be better to complete the assignments and then go take notes later based on the format the labs are given in (it gives you the instructions and)

## 📖 ??? - Live Lab: Manage Group Accounts


Scenario
You are a junior Linux systems administrator at a mid-sized software development company. The company recently reorganized its departments, and your manager has tasked you with updating the group accounts and user memberships on the Linux server to reflect the new structure.

This task is critical to ensure that team members have the correct access permissions and that the server remains organized and secure.

Your Mission is to:

Create, rename, and delete Linux group accounts.
Add and remove users from groups.
Display and verify group memberships.
Automate group management tasks using a basic shell script.
Exam Objectives
This activity is designed to test your understanding of and ability to apply content examples in the following CompTIA Linux+ objectives:

2.2: Given a scenario, perform local account management in a Linux environment.
4.2: Given a scenario, perform automated tasks using shell scripting.

---

Implementing Access Control
As a Linux administrator, it is your job to implement a role-based access control (RBAC) system that is organized and auditable.

Administrators use RBAC because it assigns permissions to groups instead of individual users, which makes managing access easier.
This process keeps things organized, secure, and easier to track and update as needed.
The /etc directory is an important directory that contains nearly all of the system configuration files in Linux.
Because the company reorganized, you need to maintain security by making sure only those who need access have the appropriate permissions.

Using the /etc Directory
In this section, you will be configuring account membership in the /etc/group file.

REMEMBER: This lab is designed for you to learn syntax and spacing by typing in the commands. Ensure you double-check the command before entering.

This lab is hosted in a Linux container that automatically logs you in as the root user.

Important Security Note: It is critical to understand that you should not use the root account in a production environment; instead login with a user account and elevate permissions as needed.

Display the contents of the /etc/group file with the command cat /etc/group.

Observe the structure of the file. Each line represents a group and follows this format:

group_name:x:group_id:group_members

group_name: The name of the group.
x: Placeholder for the group password (usually not used).
group_id: The unique numeric ID assigned to the group.
group_members: A comma-separated list of users in the group.

Answer the following question to check your understanding:

What is the GID of the root group?

---

Create and Rename Group Accounts
You will create group accounts for the engineering and operations teams. By creating groups such as "engineering" and "operations," you can assign permissions and access rights to specific roles rather than individual users. This simplifies the management of permissions and ensures that users in the same role have consistent access to resources.

Create the engineering group with a numeric group ID of 8000 by using the groupadd command: groupadd -g 8000 engineering.

The -g option in the groupadd command is used to specify the numeric Group ID (GID) for the group being created. This allows you to assign a specific GID to the group instead of letting the system automatically generate one.

Now, create an operations group with a numeric group ID of 8001: groupadd -g 8001 operations.

Verify both groups were created by using the tail command again to display the last few lines of the /etc/group file: tail /etc/group.

The tail command is used to display the last few lines of the /etc/group file. This is helpful for quickly verifying recent changes, such as renaming a group, without having to scroll through the entire file.

Next, with the groupmod command, rename the operations group to devops: groupmod -n devops operations

The -n option in the groupmod command is used to rename an existing group. This allows you to change the group's name while keeping its Group ID (GID) and other settings intact.

Now, verify the group name change with the tail command again to display the last few lines of the /etc/group file: tail /etc/group.

Confirm that you created the engineering group and renamed the devops group

---

Add Users to Groups
You will create user accounts and add them to the groups you created.

Create two user accounts with the useradd command: useradd testuser1.

Using the same command, add a testuser2 account: useradd testuser2.

Now, with the usermod command, add the testuser1 account to the engineering and devops groups.

```sh
usermod -aG engineering testuser1

usermod -aG devops testuser1
```

The -aG options will append the user to the group in case the user is a member to other groups. Check out man usermod for more information.

Without the -a option, the user would be removed from all other groups and only added to the specified group, which could cause unintended permission issues.

Repeat the above steps, but this time add testuser2 to the engineering and devops groups.

Verify the group memberships for both users by using the grep command: grep testuser /etc/group.

Confirm that you added both users to the engineering and devops groups.

---


Verify Group Memberships
You will display group memberships for users.

Change your account to the testuser1 user with the su command: su - testuser1.

You do not need to know the user's password because you are the root user. The root user may become any other user without knowing or using the user's password.

Ensure you include a space on either side of the - between su and testuser1

Check your accounts group memberships: groups.

Use the same command to show the group memberships for testuser2 by adding the intended user account: groups testuser2.

You do NOT have to be root or use privilege escalation to display group membership for yourself or other users.

Exit the testuser1 account and return to the root user account for the next exercise by simply using the exit command: exit.

Confirm that you checked group memberships for testuser1 and testuser2.



---

Remove a User from a Group
It is important to always keep role-based access control (RBAC) in mind when managing users in an organization. In the event that a user no longer requires access to a group, you should remove them. You will remove the testuser2 account from the devops group.

First, display the testuser2's group memberships again using the groups command: groups testuser2.

Next, remove testuser2 from the devops group with the gpasswd command: gpasswd -d testuser2 devops.

The gpasswd command is used to administer a group's membership. The -d option specifically removes a user from a group, ensuring they no longer have access to the permissions associated with that group.

Use the groups command to verify that testuser2 is no longer a member of the devops group: groups testuser2.

Confirm that you removed testuser2 from the devops group.


---


Automate Group Management with a Shell Script
Create a simple shell script to automate creating groups and adding users. Automating repetitive tasks like managing users and groups saves time and effort, especially in environments with many users and groups.

Create a script named group_manager.sh: vi /etc/group_manager.sh

Since you are using the vi editor, press the i key to enter Insert mode.

The vi editor opens in Command mode, which does not allow you to enter text. Press the i key to switch to Insert mode, where you will be able to enter text.

Add the following content to the script:

```sh
#!/bin/bash

group_name=$1
group_id=$2
user1=$3
user2=$4

# Create the group
groupadd -g $group_id $group_name

# Add users to the group
usermod -aG $group_name $user1
usermod -aG $group_name $user2

# Output success message
echo "Group $group_name created with GID $group_id. Users $user1 and $user2 added."
```

- #!/bin/bash: Specifies that the script should be executed using the Bash shell.
- group_name=$1, group_id=$2, user1=$3, user2=$4: These variables take input arguments passed to the script when it is executed.
- groupadd -g $group_id $group_name: Creates a group with the specified name and group ID. If the group already exists or the GID is in use, the command will fail.
- usermod -aG $group_name $user1 and usermod -aG $group_name $user2: Appends the specified users to the group without removing them from other groups.
- echo: Outputs a confirmation message to indicate that the group was created and the users were successfully added.
Press the ESC key to exit vi's Insert mode, then press :wq to write your changes and quit vi.

Next, make the script file executable by using the chmod command.

chmod +x /etc/group_manager.sh

Once, the file is executable, it will show up as green in the directory.

Run the script to create a new group and add users: /etc/group_manager.sh devteam 8003 testuser1 testuser2.

Verify the group and user memberships: grep devteam /etc/group.

Verify script created and groups with correct users have been created.

---

Grade Lab
You have completed the following tasks:

Viewed and modified the /etc/group file.
Created, renamed, and deleted group accounts.
Added and removed users from groups.
Automated group management tasks using a shell script.
Please ensure you check your work to submit for a grade.

Select check boxes to mark all tasks complete.
Submit responses to all questions/activities.
Select:

Submit in the bottom right corner, then Yes, end my lab to score and record your grade.
Save & Exit in the top corner to save your progress and return. You will have seven (7) days to complete your progress.


---


## 📖 2.2.12 - Live Lab: Manage Group Accounts


Which of the following permissions allows a user to access resources managed by another group?

answer

A
SUID


B
GPedit


C
SGID


D
EGID

> ## 🐧 Correct answer: C — SGID
> 
> **SGID** (*Set Group ID*) allows a program to run with the permissions of the file’s owning group. This can let a user access resources that belong to that group, even if the user’s usual primary group is different.
> 
> For shared directories, SGID also makes new files inherit the directory’s group ownership, helping a team work with the same group permissions. [redhat](https://www.redhat.com/en/blog/suid-sgid-sticky-bit)


---


You have a project directory /specialproj that you want to share only with members of the projdev group. Some members of the projdev group are also members of a larger group called productdev.

What should you do to meet the requirements for the /specialproj directory?

answer

A
Keep the ownership of the /specialproj directory as yourself and add your account to the projdev group.


B
Grant all projdev group members root level permissions.


C
Change the group ownership of the /specialproj directory to projdev and ensure the correct access permissions are configured for the group.


D
Change the permissions of the /specialproj directory to give all groups access to it.


> ## ✅ Correct answer: C
> 
> **C — Change the group ownership of `/specialproj` to `projdev` and ensure the correct access permissions are configured for the group.**
> 
> Linux permissions apply based on the directory’s assigned group. Making `projdev` the group owner and giving that group appropriate permissions—typically `rwx` for a shared project directory—lets only `projdev` members access it. Members of the broader `productdev` group do **not** automatically gain access just because some users belong to both groups. [redhat](https://www.redhat.com/en/blog/linux-file-permissions-explained)
> 
> For example:
> 
> ```bash
> sudo chgrp projdev /specialproj
> sudo chmod 770 /specialproj
> ```
> 
> `770` gives the owner and `projdev` full directory access while giving everyone else no access.


---

What is the meaning behind an exit code with the value 2 in relation to the groupadd command?

answer

A
GID not unique.


B
Group does not exist.


C
Cannot update group file.


D
Invalid command syntax. #CORRECT


#PROOF


![alt text](image.png)

![alt text](image-1.png)


---

## 📖 2.3.9 Lesson Review


> ## 🐧 What `export` means
> 
> `export` makes a shell variable available to programs, scripts, and subshells that you start **after** running the command. These started programs are called **child processes**.
> 
> Think of your current terminal shell as a parent. When it launches a command, it can hand the child a small list of exported settings called the **environment**. `export` adds a variable to that list. [gnu](https://www.gnu.org/software/bash/manual/html_node/Environment.html)
> 
> ## 💻 Basic syntax
> 
> Set and export in one command:
> 
> ```bash
> export PROJECT_NAME="WebsiteRedesign"
> ```
> 
> Or set it first, then export it:
> 
> ```bash
> PROJECT_NAME="WebsiteRedesign"
> export PROJECT_NAME
> ```
> 
> Both make `PROJECT_NAME` an **environment variable**.
> 
> ## 🔎 Example
> 
> ```bash
> MESSAGE="Hello"
> bash -c 'echo "$MESSAGE"'
> ```
> 
> The new Bash shell does **not** receive `MESSAGE`, because it was only a variable in the parent shell.
> 
> ```bash
> export MESSAGE="Hello"
> bash -c 'echo "$MESSAGE"'
> ```
> 
> Output:
> 
> ```text
> Hello
> ```
> 
> The second `bash` command is a child process and inherits `MESSAGE` because it was exported. Executed commands inherit the environment from their parent shell. [gnu](https://www.gnu.org/software/bash/manual/html_node/Environment.html)
> 
> ## ⚠️ Important limits
> 
> - `export` affects the **current shell session** and its future child processes—not every terminal on the system.
> - It does **not** change variables in child processes that are already running.
> - A child can change its own copy of a variable, but that change cannot travel back to the parent shell.
> - Closing the terminal usually removes variables you exported there. To set a variable automatically for future sessions, place the export command in an appropriate shell startup file, such as `~/.bashrc` for interactive Bash sessions. [askubuntu](https://askubuntu.com/questions/918783/understanding-the-export-command-becomes-the-variable-in-already-started-child)
> 
> ## 🧠 Quiz-ready wording
> 
> > Use `export VARIABLE=value` to mark a variable for inheritance by all commands and child shell processes started from the current shell.

---

![alt text](image-2.png)

A technician creates a local variable named val and sets it to 5000 at the bash prompt. The technician wants to use the variable in a script. But when the script is executed, the value of val is not set to 5000.

Which of the following commands would allow the technician to set val as an environment variable that would be available to the script?

answer

A
declare val


B
echo $val=5000


C
exec val


D
export val=5000  #CORRECT


---



All users at your site are using the bash shell. You want to set a variable that will apply to every user and always have the same value.

Which of the following shell configuration files should you place this variable in?

answer

A
.bashrc


B
.bash_login


C
.bash_profile


D
/etc/profile #MY_GUESS


---


![alt text](image-3.png)


A data engineer customizes their shell to make a more intuitive session. While working with the CLI, the user customizes the prompt and wants to display the current directory and display the system's hostname. Which command prompt modifications will provide these details? (Select two.)

answer

A
\t


B
\d


C
\h


D
\w


![alt text](image-4.png)


---
https://askubuntu.com/questions/1411833/what-goes-in-profile-and-bashrc


---

![alt text](image-5.png)


---

#PROOF

![alt text](image-6.png)


---

