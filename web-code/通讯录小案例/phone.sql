drop database if exists day17;
CREATE SCHEMA day17 DEFAULT CHARACTER SET utf8 COLLATE utf8_bin ;
use day17; 			   -- 使用数据库
create table user(   -- 创建表
	id int primary key auto_increment,
    name varchar(20),
    gender varchar(5),
	age int,
	address varchar(32),
	qq	varchar(20),
    username varchar(20),
	password varchar(20),
	email varchar(50)
);
insert  into `user` values (1,'张三','男',13,'陕西','12345','张三','123','zhangsan@itcast.cn');
insert  into `user` values (2,'李四','女',15,'北京','88888','李四','123','ls@itcast.cn');

