# 

C++ Debugging

[❮ Previous](cpp_errors.asp) [Next ❯](cpp_exceptions.asp)

- - -

Share Link Copied

/\* One delegated listener for every bar on the page, bound once even if the include is pulled in twice. The markup above is static, so the bar is part of the cached HTML and needs no script to appear - this only wires the clicks. \*/ (function(){ if(window.wsShareBar)return; window.wsShareBar=1; function pageUrl(){return location.href.split('#')\[0\];} document.addEventListener('click',function(e){ var btn=e.target&&e.target.closest?e.target.closest('.ws-share-btn'):null; if(!btn)return; var net=btn.getAttribute('data-ws-net'); if(net==='copy'){ if(!navigator.clipboard)return; var toast=btn.querySelector('.ws-copied-toast'); navigator.clipboard.writeText(pageUrl()).then(function(){ btn.classList.add('copied'); if(toast)toast.classList.add('show'); clearTimeout(btn.\_wsT); btn.\_wsT=setTimeout(function(){ btn.classList.remove('copied'); if(toast)toast.classList.remove('show'); },1600); }); return; } var url=encodeURIComponent(pageUrl()),s=''; if(net==='x'){ var title=document.title.replace(/\\s\*\[-|\]\\s\*W3Schools.\*$/i,'').trim(); s='https://twitter.com/intent/tweet?url='+url+'&text='+encodeURIComponent(title+' - W3Schools'); } else if(net==='facebook')s='https://www.facebook.com/sharer/sharer.php?u='+url; else if(net==='linkedin')s='https://www.linkedin.com/sharing/share-offsite/?url='+url; if(s)window.open(s,'\_blank','noopener,width=600,height=540'); }); })();

## Debugging

Debugging is the process of finding and fixing errors (bugs) in your program.

Bugs are mistakes that make your program crash, behave incorrectly, or give the wrong output.

Before you start debugging, make sure your code is clean and organized:

*   Use proper indentation to keep the structure clear.
*   Give your variables **clear, meaningful names** that describe what they store.

Clean code is easier to read - and easier to debug!

In the sections below, we'll introduce several common debugging techniques.

- - -

### 1\. Print Debugging

Use `cout` to print values at different points in your code to see what's going wrong:

int x = 10;  
int y = 0;  
cout << "Before division\n"; // Debug output  
int z = x / y; // Crashes!  
cout << "After division\n"; // Never runs

If you don't see "After division", the program crashed at `x / y`.

- - -

### 2\. Check Variable Values

Print variables to see if they are what you expect:

int x = 10;  
int y = 5;  
int result = x - y;  
cout << "Result: " << result << "\n"; // Result: 5

Expected 15? That means the logic is wrong: try using `x + y` instead.

- - -

### 3\. Use a Debugger Tool

IDEs like Visual Studio, Code::Blocks, and VS Code have **debuggers** that let you:

*   Pause your program (breakpoints)
*   Step through code line by line
*   Watch variables and find unexpected values

**Tip:** Start with "1. Print Debugging". Use IDE tools as you get more comfortable.

- - -

Ad

[REMOVE ADS](https://order.w3schools.com/plans)

- - -

### 4\. Learn from Error Messages

The C++ compiler and runtime errors often tell you **what went wrong** and **where**. For example:

`error: expected ';' before 'return'`

**Easy solution:** Fix the missing semicolon!

- - -

## Exception Handling

**While debugging** is about finding and fixing errors in your code, **exception handling** is a way to deal with errors while the program is running - and run specific code when something goes wrong.

Learn about [Exception Handling](/cpp/cpp_exceptions.asp) in the next chapter.

- - -

## Exercise?**What is this?**  
Test your skills by answering a few questions about the topics of this page

Drag and drop the correct operator to fix the logic so that `result` is 15.

`int x = 10;   int y = 5;   int result = x y;   cout << "Result: " << result;`

+

\-

\*

/

  
  
Submit Answer »

- - -

[❮ Previous](cpp_errors.asp) [Next ❯](cpp_exceptions.asp)

[★ +1](https://profile.w3schools.com/log-in?redirect_url=https%3A%2F%2Fwww.w3schools.com%2Fcpp%2Fcpp_debugging.asp "Your W3Schools Profile")

[Sign in to track progress](https://profile.w3schools.com/log-in?redirect_url=https%3A%2F%2Fpathfinder.w3schools.com&origin=https%3A%2F%2Fwww.w3schools.com%2Fcpp%2Fcpp_debugging.asp "Sign in to track your progress")
