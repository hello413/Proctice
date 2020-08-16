## Spring

Beans模块（容器）：是工厂模式的经典实现，Spring将管理对象称为Bean

Core核心模块：Spring框架的基本组成部分，包括IOC和DI功能

Context上下文模块：访问和配置对象的媒介

---

Bean容器：提供管理Java对象的容器

IOC：控制反转，一种设计原则，用来降低代码间的耦合度

> 实例的创建不再由调用者管理，而是由Spring容器创建，控制权由程序代码转到了Spring容器中，控制权发生了反转

DI：依赖注入，为Bean对象注入依赖属性

> 实现方式：属性注入，构造方法注入

## SpringBoot

​	它里面内置了许多默认的配置，（启动类中，自动完成的工作）

扫描类上的注解

初始化一个对象：

@Bean //配置类方法上的，以返回值作为Bean的实例对象，注入容器中

> Bean的名称为方法名

---

初始化实例一个对象，表示一个组件(Bean)

@Component  //仅仅表示一个组件(Bean)，**可作用任何层次**

@Repository  //用于**数据访问层(Dao层)**的类标识

@Service	//作用于**业务层（Service层**）

@Controller 	//作用在**控制层**（如Struts2的Action ）

---

@Configuration	配置类，启动时做配置性工作