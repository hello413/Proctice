
# 1. 用一个div模拟textarea的实现
---
## 解题思路：
---
1. 第一步
``` C
 <div class="edit" contenteditable="true">
	这里是可以编辑的内容，配合容器的 overflow ，
	多行截断，自定义滚动条，简直好用的不要不要的
</div>
```
2. 第二步 上面的代码实现了div变为可编辑状态,但是textarea标签可以在右下角自由拉伸
``` C
 <div class="edit" contenteditable="true" style="resize: both">
	这里是可以编辑的内容，配合容器的 overflow ，
	多行截断，自定义滚动条，简直好用的不要不要的
</div>
```
3. 第三步
``` C 
 .edit{
    width: 300px;
    height: 200px;
    padding: 5px;
    border: solid 1px #ccc;
    resize: both;
    overflow:auto;
}
<div class="edit" contenteditable="true">
       	 这里是可以编辑的内容，配合容器的 overflow ，
	多行截断，自定义滚动条，简直好用的不要不要的。
 </div>
```