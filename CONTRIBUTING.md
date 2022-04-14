# Contributions
## How to Contribute

1. First make sure that you have downloaded Git. If not you can [download it here](https://git-scm.com/downloads).

2. Fork this repository by pressing the “Fork” button in the upper right-hand corner of this page to create a copy of the project. (Note: make sure that you are at the forked repository. The title in the top left corner should be “your_username/Algorithms”.)

3. Clone the forked repository by pressing the green “Code” button and copying the HTTPS URL. Then open Git Bash on your computer and write ```git clone fork_url_here```.  A copy of the project will be created on your computer. 

4. Go to your local repository by writing ```cd name_of_repo``` in Git Bash.

5. Type ```git remote -v``` and check that the URL next to the word “origin” is the same URL one you copied earlier.
    * if the URL isn’t there, type ```git remote add fork_url_here```
    * if the URL is there, but it’s incorrect, type ```git remote set-url origin fork_url_here```

6. On Github, go to the project repository for this project (the title of the repository should be “ashleymays/Algorithms” in the top left corner of the page).

7. Press the green “Code” button and copy the HTTPS URL

8. In Git Bash, add the project repository as the upstream by typing ```git remote add upstream project_url_here```

9. Merge any new changes from the project repository by typing ```git pull origin master```

10. Create a new branch by typing ```git checkout -b branch_name_here```
    * Branch naming convention for this project
        * Adding a new algorithm or data structure: ```-add-name_of_alg_or_ds``` (e.g. ```-add-infix-to-postfix``` or ```-add-undirected-graph```)
    * Editing an existing algorithm or data structure: ```-edit-name_of_file``` (e.g. ```-edit-infix-to-postfix```)
    * Fixing a bug: ```-fix-issue-issue_id_here``` (e.g. ```fix-issue-14239```)

11. Open your copy of the project in your local IDE or code editor

12. After making the changes, type ```git add -A``` and then ```git commit -m “description_of_changes_here”
(e.g. ```git commit -m “added a directed graph representation”```)

13. Push your changes by typing ```git push origin branch_name_here```

14. Go to your forked repository on Github and refresh the page. Press the green button at the top of the page called “Compare and pull request”

15. Title the pull request and describe the changes you made to the project

16. Submit the pull request

If there are no errors in your pull request, then your contribution will be merged into the project.

You can read a more in-depth explanation [here](https://www.dataschool.io/how-to-contribute-on-github/).

<br />

## Folder and File Naming Conventions
Folders are titled in title casing (e.g. “Dynamic Programming”) and files are titled in all lowercase with dashes between each word for readability (e.g. “sieve-of-eratostheses.cpp”). New folders should be made if it is part of a new subtopic, like a new data structure or type of algorithm, or if there are multiple files for one algorithm or data structure representation.
