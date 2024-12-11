 create table tb_user
 (
     id     int comment '编号',
     name   varchar(50) comment '姓名',
     age    int comment '年龄',
     gender varchar(1) comment '性别'
 ) comment '用户表';

drop table tb_user;
show tables;

DESC tb_user;

show create table tb_user;

create table employee
(
    id        int comment '编号',
    workno    varchar(10) comment '工号',
    name      varchar(10) comment '姓名',
    gender    char(1) comment '性别',
    age       tinyint unsigned comment '年龄',
    idcard    char(18) comment '身份证号',
    entrydate date comment '入职时间'
)comment '员工表';

drop table employee;

# 往表中插入数据
insert into employee(id, workno, name, gender, age, idcard, entrydate)  values (1,'1','Icast','男',10,'123456789012345678','2000-01-01');
insert into employee(id, workno, name, gender, age, idcard, entrydate)  values (2,'2','Icast2','男',-1,'123456789012345678','2000-01-01');

# 查询表中的内容

select * from employee;

# 给全部字段添加数据
insert into employee values (2,'2','张无忌','男',18,'123456789012345678','2005-01-01');

# 批量添加数据
insert into employee values (3,'3','韦一笑','男',38,'123456789012345678','2005-01-01'),(4,'4','赵敏','女',18,'123456789012345678','2005-01-01');
insert into employee(id, workno, name, gender, age, idcard, entrydate) values (5,'5','周芷若','女',18,'123456789012345678','2005-01-01'),(6,'6','金庸','男',18,'123456789012345678','2005-01-01');



-- 修改id为1的数据，将name修改为shuwin
update employee set name = 'shuwin' where id = 1;

-- 修改id为2的数据，将name修改为 鼠鼠，gender修改为男
update employee set name ='鼠鼠',gender ='男' where id = 2;

-- 将所有员工的入职日期修改为 2008-01-01
update employee set entrydate ='2008-01-01';


-- 删除 gender 为女的员工
delete from employee where gender = '女';

-- 删除所有员工
delete from employee;