# 数据库

## MYSQL 基础篇

### 1 MYSQL概述

> ## 1、数据库相关概念
>
> | 名称           | 数据库管理系统                                               | 简称                               |
> | -------------- | ------------------------------------------------------------ | ---------------------------------- |
> | 数据库         | 存储数据的仓库，数据是有组织的进行存储                       | DataBase（DB）                     |
> | 数据库管理系统 | 操纵和管理数据库的大型软件                                   | DataBase Management System（DBMS） |
> | SQL            | 操作关系型数据库的编程语言，定义了一套操作关系型数据库统一标准 | Structured Query language（SQL、） |
>
> ![image-20241119083429791](mysql.assets/image-20241119083429791.png)
>
> ### 主流的关系型数据库管理系统
>
> ![image-20241119083614647](mysql.assets/image-20241119083614647.png)
>
> ## 2、MYSQL数据库
>
> ### MySQL下载及安装
>
> ### MySQL启动与停止
>
> + 启动`net start mysql80`
> + 停止`net stop mysql80`
>
> 注：以管理员身份运行
>
>  <img src="mysql.assets/image-20241119091249677.png" alt="image-20241119091249677" style="zoom:50%;" />
>
> ### MySQL客户端连接
>
> #### 方式一：MYSQL提供的客户端命令行工具
>
> ![image-20241119091449608](mysql.assets/image-20241119091449608.png)
>
> ![image-20241119091522208](mysql.assets/image-20241119091522208.png)
>
> #### 方法二：系统自带的命令行工具执行指令
>
> `mysql [-h 127.0.0.1][-p 3306] -u root -p`
>
> ![image-20241119092212531](mysql.assets/image-20241119092212531.png)
>
> 注：使用这种方式时，需要配置PATH环境变量
>
> ### MySQL数据模型
>
> ### ![image-20241119092417889](mysql.assets/image-20241119092417889.png)关系型数据库（RDBMS）
>
> 概念：建立在关系模型基础上，由多张相互连接的二维表组成的数据库
>
> 特点：
>
> 1. 使用表存储数据，格式统一，便于维护
> 2. 使用SQL语言操作，标准统一，使用方便
>
> ![image-20241119231604053](mysql.assets/image-20241119231604053.png)
>
> ### 数据模型
>
> ![image-20241119231738620](mysql.assets/image-20241119231738620.png)

### 2 SQL

#### 1）SQL通用语法

1. SQL语句可以单行或多行书写，以分号结尾。
2. SQL语句可以使用空格/缩进来增强语句的可读性
3. MySQL数据库的SQL语句不区分大小写，关键字建议使用大写。
4. 注释：
   + 单行注释：-- 注释内容 或 # 注释内容（MySQL特有）
   + 多行注释：/\*注释内容\*/

#### 2）SQL分类

| 分类 | 全称                       | 说明                                                   |
| ---- | -------------------------- | ------------------------------------------------------ |
| DDL  | Data Definition Language   | 数据定义语言，用来定义数据库对象（数据库，表，字段）   |
| DML  | Data Manipulation Language | 数据操作语言，用来对数据库表中的数据进行增删改         |
| DQL  | Data Query Language        | 数据查询语言，用来查询数据库中表的记录                 |
| DCL  | Data Control Language      | 数据控制语言，用来创建数据库用户、控制数据库的访问权限 |

#### 3）DDL

> ### DDL-数据库操作
>
> #### 1）查询
>
> ##### **查询所有数据库**
>
> ```mysql
> SHOW DATABASES;
> ```
>
> ![image-20241120104557104](mysql.assets/image-20241120104557104.png)
>
> ##### **查询当前数据库**
>
> ```mysql
> SELECT DATABASE();
> ```
>
> #### 2）创建
>
> ```mysql
> CREATE DATABASE [IF NOT EXIST] 数据库名 [DEFAULT 字符集][COLLATE 排序规则];
> ```
>
> ![image-20241120104859113](mysql.assets/image-20241120104859113.png)
>
> ![image-20241120105249142](mysql.assets/image-20241120105249142.png)
>
> ![image-20241120105809434](mysql.assets/image-20241120105809434.png)
>
> ![image-20241120110010720](mysql.assets/image-20241120110010720.png)
>
> ![image-20241120110355252](mysql.assets/image-20241120110355252.png)
>
> #### 3)删除
>
> ```mysql
> DROP DATABASE [IF EXISTS]数据库名；
> ```
>
> ![image-20241120110742163](mysql.assets/image-20241120110742163.png)
>
> #### 4)使用
>
> ```mysql
> USE 数据库名
> ```
>
> ![image-20241120111105884](mysql.assets/image-20241120111105884.png)
>
> ### DDL-表操作-查询
>
> #### 查询当前数据库所有的表
>
> ```mysql
> SHOW TABLES
> ```
>
> ![image-20241120111927638](mysql.assets/image-20241120111927638.png)
>
> #### 查询表结构
>
> ```mysql
> DESC 表名
> ```
>
> ![image-20241120154000236](mysql.assets/image-20241120154000236.png)
>
> #### 查询指定表的建表语句
>
> ```mysql
> SHOW CREATE TABLE 表名
> ```
>
> ![image-20241120154436693](mysql.assets/image-20241120154436693.png)
>
> ### DDL-表结构-创建
>
> ```mysql
> CREATE TABLE 表名(
> 	字段1 字段1类型[COMMENT 字段1注释]，
> 	字段2 字段2类型[COMMENT 字段1注释]，
> 	字段3 字段3类型[COMMENT 字段1注释]，
> 	……
> 	字段n 字段n类型[COMMENT 字段1注释]，
> )[COMMENT 表注释];
> ```
>
> 注意：[……]为可选参数，最后一个字段后面没有逗号
>
> ![image-20241120153940796](mysql.assets/image-20241120153940796.png)
>
> ### DDL-表操作-数据类型
>
> MySQL中的数据类型有很多，主要分为三类：数值类型、字符串类型、日期时间类型
>
> 参照MySQL数据类型。xlsx

### 3 函数

### 4 约束

### 5 多表查询

### 6 事务