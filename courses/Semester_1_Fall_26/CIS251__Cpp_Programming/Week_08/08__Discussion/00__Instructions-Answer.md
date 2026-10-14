Due Oct 11 11:59pm

20 points possible

# Discussion Topic: Week 8 Discussion - Object-Oriented Programming: Classes, Objects, and Encapsulation

> How can AI help review class invariants, and why must the programmer still decide what the valid object state should be?

**Requirements:** Post a substantive response of approximately 200-300 words by Thursday and reply constructively to at least two classmates by Sunday. When code is relevant, use a small code example and explain it in your own words. Cite/link any external source used.

**AI transparency:** If you use an AI assistant to brainstorm, disclose how you used it and identify at least one point you independently verified.


---

# MY ANSWER (DRAFT):

My assignment I turned in this week fo rthe BankAccount project has about 120 lines of code, excluding comments. It seemed like a fairly long and intricate program, compared to what we've written up til now. In my class constructor the invariant was the balance property. it can only non-negative, so the contructor actively rejects any negative amount and sets the balance to zero instead. The invariant here is that it can't be a negative number.

However, I hadn't originally interpreted the instructor's requirements as not allowing an initial negative balance. I interpreted it as down the road, not allowing a negative balance -- in other words, not allowign overdrafdts. But after I completed my program, all my tests passed, I asked Perplexity to evaluate my code multiple times, in fact, heres a version of the actual prompt I used,

**Prompt:**

```
MY PROGRAM WORKS! All the tests pass. Please evaluate my code for missed syntax or other errors (don't make things up, just identify any real thigns the instructor might dock me for), and suggest improvements/updates for accuracy to file comment:

CODE:

[MY FULL CODE HERE]
```

... multiple times she advised that the instructor probably meant by 'preserving a nonnegative balance' -- not just 'preserving' (understood as you are already STARTING with a nonnegative balance) ... anyway, AI kept telling me whenever I asked for a code review and an accuracy review that I should not accept a negative balance. There doesn't seem to be a super elegant way to not create the account if the amount entered is negative, so I opted for create the account but set the intial balance to zero if they enter a negative nubmer.

So, this is real-life scenario of how AI actually helped me review class invariants. And although I argued with AI many times that this wasn't required, in the end, after digging a bit deeper for a better understanding, i came to the conclusion that the assistant was correct in this case and adopted her suggestion for to apply the invariant rule to the constructor










# AI-ASSISTED DRAFT:

## 📌 Discussion Post Body

AI can help review class invariants by looking for places where an object could be created or changed into an invalid state. In my BankAccount project, I asked an AI assistant to review code that had already passed all of my tests. It repeatedly suggested that the nonnegative-balance rule should apply in the constructor, not only when handling later deposits and withdrawals. At first, I disagreed because I understood the requirement as preventing overdrafts after the account was created. After examining the assignment and the purpose of an invariant, I concluded that the assistant was right: a valid `BankAccount` should never have a negative balance, even immediately after construction. Once I realized that, I updated the constructor, reran my tests, and confirmed that the program still worked correctly.

A class invariant is a condition that must be true for every valid object: it is established when the constructor finishes and preserved by the class’s public operations.  For a different example, imagine a helicopter class in a game where the maximum allowed altitude is 25,000 feet. The invariant would be `altitude <= 25000`. If the game tries to create a helicopter above that limit, the constructor can clamp it to the maximum: 

```cpp
Helicopter::Helicopter(double initialAltitude) {
    const double MAX_ALTITUDE = 25000.0;

    if (initialAltitude > MAX_ALTITUDE) {
        altitude = MAX_ALTITUDE; // documented fallback
    } else {
        altitude = initialAltitude;
    }
}

void Helicopter::climb(double feet) {
    const double MAX_ALTITUDE = 25000.0;

    altitude += feet;
    if (altitude > MAX_ALTITUDE) {
        altitude = MAX_ALTITUDE;
    }
}
```

The constructor establishes the valid state, while `climb` preserves it by preventing the helicopter from exceeding the game’s ceiling.

AI can flag that `altitude = 30000` might violate the rule, but it cannot decide the game’s actual rule. The programmer must determine whether an excessive starting altitude should be rejected, silently limited to 25,000 feet, or treated as an error. In my BankAccount case, I ultimately chose to set an invalid negative initial balance to zero, but that was my design decision based on the assignment—not something AI could decide for me. 

**🤖 AI transparency:** I used Perplexity to organize my explanation and condense this response. I independently verified the constructor-and-invariant idea by reviewing my BankAccount code, updating the constructor to enforce the nonnegative-balance rule, and rerunning my tests to confirm that the program still passed. I also verified that constructors are responsible for establishing an object’s initial valid state. 



### References:
- https://www.rahulpnath.com/blog/constructor-and-constraints
- https://www.perplexity.ai/search/3aefad85-36ef-444f-8a7a-14d81b21576b
- https://www.perplexity.ai/search/bce63cad-39c3-4a5a-868d-b851ae6ae4b1
- https://www.justsoftwaresolutions.co.uk/cplusplus/invariants.html
- CPSC121 Lecture 12.3: Class Invariants: https://www.youtube.com/watch?v=DqafhFBAneU


