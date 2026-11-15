# 

C++ Exceptions

[❮ Previous](cpp_debugging.asp) [Next ❯](cpp_input_validation.asp)

- - -

Share Link Copied

/\* One delegated listener for every bar on the page, bound once even if the include is pulled in twice. The markup above is static, so the bar is part of the cached HTML and needs no script to appear - this only wires the clicks. \*/ (function(){ if(window.wsShareBar)return; window.wsShareBar=1; function pageUrl(){return location.href.split('#')\[0\];} document.addEventListener('click',function(e){ var btn=e.target&&e.target.closest?e.target.closest('.ws-share-btn'):null; if(!btn)return; var net=btn.getAttribute('data-ws-net'); if(net==='copy'){ if(!navigator.clipboard)return; var toast=btn.querySelector('.ws-copied-toast'); navigator.clipboard.writeText(pageUrl()).then(function(){ btn.classList.add('copied'); if(toast)toast.classList.add('show'); clearTimeout(btn.\_wsT); btn.\_wsT=setTimeout(function(){ btn.classList.remove('copied'); if(toast)toast.classList.remove('show'); },1600); }); return; } var url=encodeURIComponent(pageUrl()),s=''; if(net==='x'){ var title=document.title.replace(/\\s\*\[-|\]\\s\*W3Schools.\*$/i,'').trim(); s='https://twitter.com/intent/tweet?url='+url+'&text='+encodeURIComponent(title+' - W3Schools'); } else if(net==='facebook')s='https://www.facebook.com/sharer/sharer.php?u='+url; else if(net==='linkedin')s='https://www.linkedin.com/sharing/share-offsite/?url='+url; if(s)window.open(s,'\_blank','noopener,width=600,height=540'); }); })();

## Exceptions

As mentioned in the [C++ Errors](cpp_errors.asp) chapter, different types of errors can occur while running a program - such as coding mistakes, invalid input, or unexpected situations.

When an error occurs, C++ will normally stop and generate an error message. The technical term for this is: C++ will throw an **exception** (throw an error).

- - -

## Exception Handling (try and catch)

Exception handling lets you **catch and handle errors** during runtime - so your program doesn't crash.

It uses three keywords:

*   `try` - defines the code to test
*   `throw` - triggers an exception
*   `catch` - handles the error

### Example

try {  
  // Code that may throw an exception  
  throw 505;  
}  
catch (int errorCode) {  
  cout << "Error occurred: " << errorCode;  
}

Here, the program throws an exception with the value `505`, which is caught and handled in the `catch` block.

- - -

## Real-Life Example: Age Check

We can use exception handling to check if a user is old enough:

### Example

try {  
  int age = 15;  
  if (age >= 18) {  
    cout << "Access granted - you are old enough.";  
  } else {  
    throw (age);  
  }  
}  
catch (int myNum) {  
  cout << "Access denied - You must be at least 18 years old.\\n";  
  cout << "Age is: " << myNum;  
}

[Try it Yourself »](trycpp.asp?filename=demo_try_catch)

#### Example explained

We use the `try` block to test some code: If the `age` variable is less than `18`, we will `throw` an exception, and handle it in our `catch` block.

In the `catch` block, we catch the error and do something about it. The `catch` statement takes a **parameter**: in our example we use an `int` variable (`myNum`) (because we are throwing an exception of `int` type in the `try` block (`age`)), to output the value of `age`.

If no error occurs (e.g. if `age` is `20` instead of `15`, meaning it will be be greater than 18), the `catch` block is skipped:

### Example

int age = 20;  

[Try it Yourself »](trycpp.asp?filename=demo_try_catch2)

You can also use the `throw` keyword to output a reference number, like a custom error number/code for organizing purposes (`505` in our example):

### Example

try {  
  int age = 15;  
  if (age >= 18) {  
    cout << "Access granted - you are old enough.";  
  } else {  
    throw 505;  
  }  
}  
catch (int myNum) {  
  cout << "Access denied - You must be at least 18 years old.\\n";  
  cout << "Error number: " << myNum;  
}

[Try it Yourself »](trycpp.asp?filename=demo_try_catch3)

- - -

Ad

[REMOVE ADS](https://order.w3schools.com/plans)

- - -

## Handle Any Type of Exceptions (...)

If you do not know the `throw` **type** used in the `try` block, you can use the "three dots" syntax (`...`) inside the `catch` block, which will handle any type of exception:

### Example

try {  
  int age = 15;  
  if (age >= 18) {  
    cout << "Access granted - you are old enough.";  
  } else {  
    throw 505;  
  }  
}  
catch (...) {  
  cout << "Access denied - You must be at least 18 years old.\\n";  
}

[Try it Yourself »](trycpp.asp?filename=demo_try_catch_dots)

- - -

## Exercise?**What is this?**  
Test your skills by answering a few questions about the topics of this page

What is the purpose of exception handling in C++?

  

To execute code faster

To handle errors and execute code when an error occurs

To ignore errors during execution

To organize code into classes and objects

  
Submit Answer »

- - -

  

[❮ Previous](cpp_debugging.asp) [Next ❯](cpp_input_validation.asp)

[★ +1](https://profile.w3schools.com/log-in?redirect_url=https%3A%2F%2Fwww.w3schools.com%2Fcpp%2Fcpp_exceptions.asp "Your W3Schools Profile")

[Sign in to track progress](https://profile.w3schools.com/log-in?redirect_url=https%3A%2F%2Fpathfinder.w3schools.com&origin=https%3A%2F%2Fwww.w3schools.com%2Fcpp%2Fcpp_exceptions.asp "Sign in to track your progress")
