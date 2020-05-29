## 分支的创建

* 查看分支：`git branch`

* 创建分支：`git branch name`

* 切换分支：`git checkout name `

* 创建+切换分支：`git  checkout -b name`

* 合并某分支到当**前分支**：`git merge name `

* 删除分支：`git  branch -d name `

## 推送到远程仓库

1. 首先需要把路径移动当需要推送的文件里.

2. 使用 `git push` 就可以推送了.

* 注意：在第一推送时要加上参数`-u`，这样本地的`master `和远程的`master`分支会合并.


* 除了上述使用`git push`的方法外，也可以使用`git push -u origin master`，其中`origin`为远程仓库名字.


