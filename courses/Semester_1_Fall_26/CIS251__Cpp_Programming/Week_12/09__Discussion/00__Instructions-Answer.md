# Week 12 Discussion - Files, Streams, Persistence, and Program Testing

> How can AI generate useful test data without introducing fabricated assumptions about your file format or requirements?

**Requirements:** Post a substantive response of approximately 200-300 words by Thursday and reply constructively to at least two classmates by Sunday. When code is relevant, use a small code example and explain it in your own words. Cite/link any external source used.

**AI transparency:** If you use an AI assistant to brainstorm, disclose how you used it and identify at least one point you independently verified.



---

# MY ANSWER (DRAFT):

AI can be a great time saver when it comes to creating tests and generating useful test data. But, a big challenge many popular chatbots has is hallucinating details. For instance, in my week 12 assignment for file I/O basics, I asked Perplexity to ...

I'm not really what this is asking. But, basically I think its key for you to provide guardrails, requirements, limitations -- basically tell ai a list of what an excellent response must and must not have. The more specific you are, usually the better AI performs. So if I was creating test data for a budget tracking program, I would consider the types of data a good-faith user would likely enter. A user in a budgeting app can expect to be able to enter both integers and 2-precision decimals.... So, if I asked AI to create an array of monetary values I could use to test the app, since I'm american and many of the AI companies are based in USA, it would be reasonable to expect the assumed units to USD. So, I can't expect the AI to know if I need EUROS or YEN without telling her. Also, I can't expect the chatbot to know that I want all the data to be 2-digit decimal precison unless I tell her that...

this is my basic idea ...

BAD TEST DATA EX:
[Add a table of good test data, 2 rows 4 cols including an index]

GOOD TEST DAT EX here:
[]

[Show a tiny MVP of what a sample test harness of c++ code would be ]

[AI TRANSPARENCY TEMPLATE:

**🤖 AI transparency:** I used Perplexity to organize my explanation, condense this response and expand my Net() object example. I independently verified that the 3 monthly net amounts add to 13,200 without taxing those amounts again.
]

# AI-ASSISTED DRAFT:

AI can save time when generating test data, but it needs clear requirements instead of making assumptions about what a program accepts. I would provide the assignment instructions, a sample input file, and a list of allowed and prohibited values and output formats. I would also tell AI to ask about missing requirements rather than fill in the gaps.

For example, if a budgeting app should accept whole numbers and amounts with one or two decimal places, then `12`, `12.5`, and `12.35` are valid, while `12.25234` is not. Saying “two-decimal precision” could be misunderstood as requiring exactly two digits after the decimal point. That would incorrectly classify `12.5` and `12` as invalid.

### ❌ Incorrectly labeled test data

| Index | Input | Expected result | Problem |
|---|---|---|---|
| 1 | `12.5` | Reject | One decimal place is allowed |
| 2 | `12.25234` | Accept | Exceeds two decimal places |

### ✅ Useful test data

| Index | Input | Expected result | Purpose |
|---|---|---|---|
| 1 | `12` | Accept | Tests a whole number |
| 2 | `12.35` | Accept | Tests two decimal places |
| 3 | `12.4` | Accept | Tests one decimal place |

I would also require AI to follow the actual file structure without inventing headers, separators, or extra fields. Generated tests should include expected results so I can compare them with my program’s output.

This conversation demonstrated the problem: AI initially required exactly two decimal places and introduced `stringstream`, which we have not covered. Both choices went beyond my requirements. Clear instructions help, but I still need to review the output rather than assume it is correct.

### 🤖 AI transparency

I used Perplexity to organize my explanation and draft the test tables. I independently checked each table entry against my stated rule allowing whole numbers and amounts with one or two decimal places.


### References:
-

### #NOTES:
- 