Due Oct 18 11:59pm

20 points possible

# Discussion Topic: Week 14 Discussion - AI-Assisted Software Engineering for C++: Prompting, Verification, and Responsible Use

> Which parts of programming judgment can AI accelerate, and which must remain the programmer's responsibility?

**Requirements:** Post a substantive response of approximately 200-300 words by Thursday and reply constructively to at least two classmates by Sunday. When code is relevant, use a small code example and explain it in your own words. Cite/link any external source used.

**AI transparency:** If you use an AI assistant to brainstorm, disclose how you used it and identify at least one point you independently verified.


---

# MY ANSWER (DRAFT):


## 📝 Week 14 Discussion: AI-Assisted Software Engineering for C++: Prompting, Verification, and Responsible Use

AI is great at rapid data processing and research. Where it seems to lack is understanding clear intent and sometimes nuance. My experience with AI taught me that one of the places it can really accelearate software progress is in developing tests and identifying risk/cost-benefit?reward.

For instance ... in the current assignment, Google AI Studio gemini?? helped identify two issues that weren't very intuitive to me, and without ai doing code review, if it had been a real deal, it might have shipped to production before any problem was even identified. That could have cost an employer / client thousands to millions of dollars in downtime or legal lawsuit exposure, etc.

Blah ... for instance ?? ... both of the two likely logic errors he identified (Unchecked Mixed-Unit Addition in operator+ and Exact Floating-Point Comparison (dist == 1.0) in display()) were items I corrected for my assignment.

.. The parts a human/I/the programmer must be responsible for are determining whether improvement suggestions are worth it — ie, the AI can Identify risks and rewards, but the human must be the one to make a final determination based on those facts (ex, does the feature overengineer or overcomplicate something such that it would no longer be single-job, doe the fix improve code cleanliness at the expense of performance, would performance be improved slightly with little ROI taking 9 hours to implement and costing 1 hr of downtime each time repair/maintenance is needed?, etc.)

[include relevant code snippet]

[Conclusion here]

**🤖 AI transparency:** I used Perplexity to organize my explanation, condense this response and expand my Net() object example. I independently verified that the 3 monthly net amounts add to 13,200 without taxing those amounts again.[decide to make this more well-structured if appropriate for the multiple ai sources used, and also consider that Perplexity wasn't the primary agent in this case]


# AI-ASSISTED DRAFT:


## 📝 Week 14 Discussion Post (Preserved)

AI can speed up the mechanical, exploratory parts of programming: reading code quickly, proposing test cases, and flagging risks. This week, Google AI Studio (Gemini) found two logic errors in my Week 10 `Distance` class that I hadn't noticed. First, `operator+` added raw numbers without checking units, so 1 foot + 6 inches gave `7.00 feet`. Second, the singular/plural label used an exact floating-point comparison, `dist == 1.0`. A reviewer like this can catch defects before release, when they are cheapest to fix.

But AI can only identify a risk. The programmer decides what is worth fixing and what fits the project's constraints. I made these calls myself:

- **Course limits:** Copilot suggested `static` helper functions. My course hasn't covered `static`, so I rewrote them as ordinary member functions.
- **Design choice:** The assignment gave no rule for mixed units, so I chose to convert the right operand into the left operand's unit. The trade-off is that operand order can change the result unit.
- **Pushing back:** An AI called the floating-point issue out of scope. I disagreed, because it was a real bug in my own code, and I fixed it.

```cpp
// Treat values within 0.005 of 1.0 as singular (matches 2-decimal display).
bool isOne = abs(dist - 1.0) < 0.005;
return (isOne ? "foot" : "feet");
```

In my own words: floating-point sums can land just below 1.0, such as `0.2 + 0.7 + 0.1`, which is stored as `0.9999999999999999`. An exact `==` check would print "1.00 feet". The tolerance of 0.005 matches the two-decimal display, so the label follows what the user sees.

AI accelerates finding problems and generating tests. The programmer stays responsible for verifying each suggestion, judging whether it is worth the complexity, and owning the final design.

**🤖 AI transparency:** I used Google AI Studio (Gemini) as my primary code reviewer, Copilot for compile-error help, and Perplexity to organize this post and refine my wording. I independently verified the fixes by running Tests 12-15 and confirming that the mixed-unit sums and the `1.00 foot` label matched my expected output.

## ⚠️ Validation Notes (Appended)

I checked the post against Gemini's review as the source of truth.

- **Pushing-back bullet is misleading:** Gemini itself recommended the exact fix, `abs(dist - 1.0) < 0.005`, and explained the two-decimal mismatch. The "out of scope" claim came from Perplexity and contradicted Gemini. Reword it so you pushed back on a Perplexity comment, and say the fix came from Gemini and you verified it.
- **Design-choice bullet omits Gemini's options:** Gemini offered two fixes for mixed units: convert the units or throw an exception. You picked conversion from Gemini's options, which is a better framing than "no rule given".
- **Gemini's expected values match yours:** Its mixed-unit test expected `1.50 feet` for `a + b`, and `18.00 inches` for `b + a`. Your Tests 12 and 13 match those numbers exactly.
- **Order-dependence wording:** Gemini flagged order dependence because the values were wrong (`7.00` either way). Your fix makes the values correct. Only the result's unit label still depends on order.
- **Test 15 differs from Gemini's test:** Gemini's edge case was `Distance(3.1, 4.1, inch)`, which prints `1.00 inches`. Your Test 15 uses `0.2 + 0.7 + 0.1` instead. Both show the same problem, but credit Gemini for the problem and the 0.005 fix, and say Test 15 is your own input.
- **Location of the comparison:** Gemini placed `dist == 1.0` in `display()`. In your final code it lives in `setUnitText()`, so your post's snippet is correct for your version.
- **Other Gemini suggestions you used:** Gemini also recommended `enum class Unit` and `const` on `display()` and `operator+`. Consider mentioning those in the transparency note, since it was your first reviewer.
- **`const` attribution in your AI log:** Gemini recommended `const` only on `display()` and `operator+`. The point that the helpers must be `const` too is a consequence you hit and I explained, not something Gemini stated.
- **Gemini suggestions not adopted:** Moving formatting out of `display()` and renaming constructor parameters were skipped. You could cite these as accepted-versus-rejected examples.
- **Unrelated lookup:** I opened the `@see` GitHub link from your header, and it resolves to your profile. It isn't needed for the post. [github](https://github.com/codewizard13)




### References:
-  

### #NOTES:
- 