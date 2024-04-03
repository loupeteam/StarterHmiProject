Here is a short document describing Loupe's general Git workflow, adapted for Open Source contribution and collaboration.

**We mostly use:**  
Git (source/version control)  
GitHub (storing repos, reviewing code)  
GitFlow (process and branching conventions)

## The major takeaways

- Scope small PRs that are convenient to review and digest
- We ❤️ code reviews
- Name PRs like commits, but shorter
- For discussion about project direction or features, jump in the Slack at [SASE](https://sase.space/)

**small note: if you use GitLab, the term Merge Request or MR is equivalent to a Pull Request or PR in GitHub.*

## Commit Messages

A great commit message concisely and meaningfully answers this question:

> *If applied, this commit will **[commit subject line]*.**
> 

<aside>
💡 This is also known as **“imperative mood”** which is essentially a command or instructions.

</aside>

We use this form because the commits describe what they will do. Minor notes, please capitalize messages and don’t bother adding a period or punctuation.

This link is a good resource: [How to Write a Git Commit Message (cbea.ms)](https://cbea.ms/git-commit/)

**Examples:**

`Implement node-based extrapolation method`

`Increase acceleration parameter for new drive`

`Remove deprecated references to AsString`


## Naming Branches

Our branch names use either camel case or kebab case. 
We prefer specific names over general ones.

**Examples:**

✅`feature/update-protobuf-timestamps-to-utc`

is both brief and descriptive!

❌`feature/protobuf` is non-descriptive and generic

- ***More on branch prefixes***
    
    We commonly use these branch name prefixes to clarify what the type of branch (re: GitFlow):
    
    - **feature** - ie `feature/update-protobuf-timestamps-to-utc`
    - **release** - ie `release/1.0.0` or `release/epsilon` (see explanation below)
    - **hotfix** - ie `hotfix/fix-robotfast-page-fault`
    
    Less common, but useful:
    
    - **debug** - a debug effort that you want to share `debug/locate-page-fault`
    - **experimental** - a branch that is less likely to be actually merged, but you still want to push to backup and share ie `experimental/redefine-accel-params-as-optional`
    
    <aside>
    💡 ***What if I inherited a branch with a confusing name, or accidentally named it too generally, or spelled something wrong, etc?*** 
    Create a new branch off of your current branch, with a better name. 
    Note: you’ll need to relink any PRs if you already started them.
    
    </aside>
    

## Pull Requests

### We ❤️ small, focused PRs

What makes a well-scoped PR? 

It’s not just about number of lines changed, because adding libraries often adds thousands of lines. Or sometimes there is an idea applied across a few files, which is a lot of lines that are quick to review.

- ***Rule of thumb***
    
    ### Small but meaningful
    
    A great PR has enough meaningful work to review and comment on, while not requiring a reviewer to read through 100s of lines of code.
    
    A soft rule: if you find yourself saying “this PR does X and Y and Z” it’s possible that X, Y, and Z could be their own branches and associated PRs.
    

### Titles

A great PR title is just like a great commit message - short and meaningful, and in the imperative mood (reads like a command).

Example: This PR will…
`Update protobuf timestamps to UTC` 

- **Title:** Short and descriptive summary.
- Capitalized and written in imperative present tense (”this PR Will… [the title]
- Does not end with a period
- **More on why**
    
    When reading through Git history, it’s helpful if seeing branches being merged tells a story about what has happened.
    

### Descriptions

These contain more detailed, explanatory text describing the PR for the reviewer. We often use a “What” and “Why” format. If there’s any special or unique info you’d like the reviewer to know, this is also a good place to store it. Or speak with them directly.

- **Example**
    
    Here is an example of a complete PR description. This might seem short, but it’s sufficient for the task. Depending on the size of your PR, the description may be longer. Feel free to use this space to explain any special info the reviewers may need.
    
    ## What 
    
    Adds an 'Edit on Github' button to all pages that will redirect users to the repository page. (include pictures)
    
    ## Why
    
    This addition lowers the barrier to entry for contributing to the repository.`
    

### Using Draft PRs and “Review as you go”

PRs are our mechanism for showing, reviewing, and approving changes to a project. 

In GitHub, there are options for either normal Pull Requests or “Draft” Pull Requests. 

> **Please create draft PRs when you begin new work on a feature branch.
Turn them to non-draft PRs when you are ready for a full review.**
> 
- **More on this practice**
    
    For collaborators outside of Loupe, it is easier to share context and discuss the addition of new features __before__ the work is started. This can prevent time spent on features that a discussion might decide are better off not included in the project.
    
    Creating a draft PR as soon as work begins on a branch, gives visibility for reviewers into the dev’s process and provides a place for discussions to happen **before** work is wrapped up.
    
    The intention isn’t to “look over the contributor’s shoulder”, but instead to allow reviewers to see the work as it develops instead of “all at once” (easier to schedule, get context). Additionally the reviewer can see that the general direction or code design is sound. The intention is that reviewers will only reach out if the direction seems drastically off. Note that availability of Loupe staff for review is subject to change and we cannot guarantee any timeline for review on open source contributions.
    
    The alternative, which we **don’t** recommend, is waiting to make a PR until work is “ready for review” before creating it. The downsides are a higher risk of miscommunications instead of seeing the work as it gets built. It also means the reviewer gets a “chunk” of work to review, which can be harder to schedule.
    
    On another level, the existence of draft PRs aids in understanding what branches are actively being worked on, what work is happening. On larger projects, when combing through lists of branches, seeing draft PRs can indicate some intention of what’s happening.
    

### PR review

For open source contributions, review is typically done asynchronously. In this format, the reviewer will read and make comments on the PR via GitHub, when they time and the author can respond in a similar manner. If quicker, more direct communication is desirable you are welcome to join the [SASE Slack workspace](https://sase.space/) and reach out in a relevant channel (`#platforms-br`, `#platforms-beckhoff`, `#vizualisation`, etc.). It’s up to the folks involved as to what method is ideal.

Generally, when a contributor opens a PR, a Loupe maintainer will try to either review promptly or communicate an expected timeline for review. Once a PR has been approved it will be merged in. Availability of Loupe devs is subject to change frequently and as such the timeline for the review process may vary.

## **Versioning**

Loupe uses semantic versioning (https://semver.org/).

Version numbers follow the convention 
*`Major.Minor.Patch*` 
where version 1.2.3 would be “major version 1, minor version 2, patch version 3”.