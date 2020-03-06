## vue.js

---

Object.freeze()，这会阻止修改现有的属性，也意味着响应系统无法再追踪变化。
<font color=red size=5px>指令</font>
- v-bind：将这个元素节点的 title 特性和 Vue 实例的 message 属性保持一致
- v-if：将根据表达式 seen 的值的真假来插入/移除 <p> 元素
- v-for ：可以绑定数组的数据来渲染一个项目列表
- v-on ：添加一个事件监听器，通过它调用在 Vue 实例中定义的方法
- v-model ：能轻松实现表单输入和应用状态之间的双向绑定
- v-bind ：将待办项传到循环输出的每个组件中
- v-once 指令:你也能执行一次性地插值，当数据改变时，插值处的内容不会更新。但请留心这会影响到该节点上的其它数据绑定
- v-html:为了输出真正的 HTML

<font color=red size=5px>钩子</font>	
不要在选项属性或回调上使用箭头函数，比如 created: () => console.log(this.a) 或 vm.$watch('a', newValue => this.myMethod())。因为箭头函数并没有 this，this 会作为变量一直向上级词法作用域查找，
created 钩子可以用来在一个实例被创建之后执行代码
