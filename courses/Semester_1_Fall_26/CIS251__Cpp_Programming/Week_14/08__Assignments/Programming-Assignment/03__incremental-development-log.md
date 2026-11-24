# 🛠️ Incremental Development Log

## 📘 Assignment Information

- **Course:** CIS-251 — C++ Programming
- **Assignment:** Week 14 — AI-Assisted Software Engineering for C++: Prompting, Verification, and Responsible Use
- **Author:** Eric L. Hepperle
- **Program:** Distance class with AI-suggested updates, version 1.0 (WIP)

## 📋 Initial Design and Planning

I chose week 10's distance assignment because it was complex enough and I remembered I didn't set it up to do unit conversions because it was out of scope. I thought it would be a perfect opportunity for this assignemnt 14 ai assisted challenge.


## 🏗️ Incremental Implementation

### 1. Evaluate the code with Google AI studio

#### Inital Prompt:

I signed up for **Google Ai studio (Gemini)**, then based on this week's tutorial, posted the following prompt:


```md
#PROMPT:

I am a beginning C++ student. My program uses only concepts through classes,
vectors, file I/O, and exceptions. Do not introduce libraries or techniques
outside those topics.

Here is my requirement:

Give me (1) a plain-language explanation, (2) five test cases, and (3) a code
review limited to concepts already covered in CIS 251, based on the draft code
as context.

Here is my current code:

[full Week 10 final Main.cpp code here]

Identify two likely logic errors. Explain each error and suggest a small test
that would expose it. Do not rewrite the entire program.
```

> 📌 #TIP ? iF I was starting over, I would merge the very last paragraph under the "Here is my requirement" section, possibly renamed as "REQUIREMENTS" and as a concise bullet list

#### Results:



Gemini gave the required plain language explanation, five test cases, and the appropriately limited code review.

> - #GOTCHA: _While the programming task description says to submit a revised program and "reject/correct at least one questionable or unnecessary suggestion", it doesn't clearly say to what degree to revise the program. In other words, though it clearly says to reject at least one suggestion, it doesn't say whether to implement at least one suggestion, or whether it is required to implement ALL the non-questionalbe suggestions, or just one, or as many as I choose._
>
>   Therefore, I'm making an executive decision for time sake to only implement two suggestions, so as not to make this overly complex.

Full prompt response [here](./05__AI-Gen-Review.md)

---
