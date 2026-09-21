Due Sep 20 11:59pm

20 points possible

# Week 5 Discussion - Functions, Scope, Decomposition, and Reuse

What makes an AI-suggested function decomposition good or poor from the standpoint of cohesion and coupling?

**Requirements:** Post a substantive response of approximately 200-300 words by Thursday and reply constructively to at least two classmates by Sunday. When code is relevant, use a small code example and explain it in your own words. Cite/link any external source used.

**AI transparency:** If you use an AI assistant to brainstorm, disclose how you used it and identify at least one point you independently verified.

---

# MY ANSWER (DRAFT):

You want optimally a balance between low coupling and high cohesion for code that is highly flexible, yet easy to maintain. You can refactor internals without asffecting the rest of the system, you can swap complete modules without affecting the system. Coupling means how much a module depends on another module to work.

Loosly coupled vs tightly coupled.

Cohesion: low cohesion to high cohesion. Low cohesion = a class with many responsibilities (utility classes). Strong cohesion: a specific function that can work in isolation from the rest of the world.

How to achieve the sweet spot?
- 1. Naming - give specific names to modules
- 2. Group by feature/behavior (functional cohesion)
- 3. High cohesion (everyone knows their specific roles and stays in their own lane)
- 4. Coupling in functions, classes, modules, services-apis
- 

AN AI-suggested function decomposition is good if it has high cohesion and low coupling. In other words, if it suggests code that is one mega-utility-swiss-army-knife type module with lots of different jobs, then that's not a good suggestion. We want high cohesion meaning each module --  in the current assignement 'function' -- has its' own job. That way if the module fails it has the least possibility of negatively affecting the system. In the real world this is called production down-time, and that's really bad!


### References:
- https://www.youtube.com/watch?v=7pdrZDqEPIw


### 🤖 AI Assistance Log:

- Perplexity: used to brainstorm, clarify terms, and formalize/format my thoughts.



---

# MY AI-ASSISTED FINAL ANSWER:


## 🛠️ Revised Discussion Post

A good AI-suggested function decomposition balances **high cohesion** with low coupling. High cohesion means that each function has one clear, closely related responsibility. Low coupling means that functions do not depend heavily on each other’s internal details, global variables, or unnecessary shared data. This balance makes code easier to test, reuse, update, and troubleshoot.

For example, an AI suggestion would be poor if it creates one large “utility” function that validates input, calculates totals, prints results, saves a file, and handles errors all at once. Although that approach may work initially, changing one responsibility could accidentally affect the others. It also makes the function difficult to reuse because it performs too many unrelated tasks.

A better decomposition separates each responsibility into a focused function:

```cpp
double calculateTotal(double price, int quantity) {
    return price * quantity;
}

bool isValidQuantity(int quantity) {
    return quantity > 0;
}

void displayTotal(double total) {
    cout << "Total: $" << total << endl;
}
```

Each function has a single purpose: one validates, one calculates, and one displays output. This is an example of high cohesion because the code inside each function supports one task. The functions are also loosely coupled because `calculateTotal()` does not need to know how the result will be displayed.

AI-generated code should still be reviewed instead of accepted automatically. AI may create too many tiny functions, which can make a program harder to follow, or it may combine unrelated work into one large function. I used AI to help improve organization and wording in this post, but I independently verified that high cohesion and low coupling are common software-design goals.