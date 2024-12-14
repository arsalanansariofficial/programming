# SQL 50

This repository contains solutions to track **LeetCode SQL 50**

## Select

Queries focusing on **Select** command

### 01757. Recyclable and Low Fat Products

#### Statement

```sql
Table Products

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| product_id  | int     |
| low_fats    | enum    |
| recyclable  | enum    |
+-------------+---------+

product_id is the primary key (column with unique values) for this table.

low_fats is an ENUM (category) of type ('Y', 'N') where 'Y' means this product is low fat and 'N' means it is not.

recyclable is an ENUM (category) of types ('Y', 'N') where 'Y' means this product is recyclable and 'N' means it is not.

Write a solution to find the ids of products that are both low fat and recyclable.

Input:

Products table:
+-------------+----------+------------+
| product_id  | low_fats | recyclable |
+-------------+----------+------------+
| 0           | Y        | N          |
| 1           | Y        | Y          |
| 2           | N        | Y          |
| 3           | Y        | Y          |
| 4           | N        | N          |
+-------------+----------+------------+

Output:
+-------------+
| product_id  |
+-------------+
| 1           |
| 3           |
+-------------+

Explanation: Only products 1 and 3 are both low fat and recyclable.
```

#### Schema

```sql
drop database sql_50;

create table if not exists products (product_id int, low_fats enum('y', 'n'), recyclable enum('y','n'));

truncate table products;

insert into products (product_id, low_fats, recyclable) values ('0', 'y', 'n');
insert into products (product_id, low_fats, recyclable) values ('1', 'y', 'y');
insert into products (product_id, low_fats, recyclable) values ('2', 'n', 'y');
insert into products (product_id, low_fats, recyclable) values ('3', 'y', 'y');
insert into products (product_id, low_fats, recyclable) values ('4', 'n', 'n');
```

### 00584. Find Customer Referee

#### Statement

```sql
Table: Customer

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| name        | varchar |
| referee_id  | int     |
+-------------+---------+

In SQL, id is the primary key column for this table.

Each row of this table indicates the id of a customer, their name, and the id of the customer who referred them.

Find the names of the customer that are not referred by the customer with id = 2.

The result format is in the following example.

Input:
Customer table:
+----+------+------------+
| id | name | referee_id |
+----+------+------------+
| 1  | Will | null       |
| 2  | Jane | null       |
| 3  | Alex | 2          |
| 4  | Bill | null       |
| 5  | Zack | 1          |
| 6  | Mark | 2          |
+----+------+------------+

Output:
+------+
| name |
+------+
| Will |
| Jane |
| Bill |
| Zack |
+------+
```

#### Schema

```sql
drop database sql_50;

create table if not exists customer (id int, name varchar(25), referee_id int);

truncate table customer;

insert into customer (id, name, referee_id) values ('1', 'will', null);
insert into customer (id, name, referee_id) values ('2', 'jane', null);
insert into customer (id, name, referee_id) values ('3', 'alex', '2');
insert into customer (id, name, referee_id) values ('4', 'bill', null);
insert into customer (id, name, referee_id) values ('5', 'zack', '1');
insert into customer (id, name, referee_id) values ('6', 'mark', '2');
```

### 00595. Big Countries

#### Statement

```sql
Table: World

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| name        | varchar |
| continent   | varchar |
| area        | int     |
| population  | int     |
| gdp         | bigint  |
+-------------+---------+

name is the primary key (column with unique values) for this table.

Each row of this table gives information about the name of a country, the continent to which it belongs, its area, the population, and its GDP value.

A country is big if:

it has an area of at least three million (i.e., 3000000 km2), or it has a population of at least twenty-five million (i.e., 25000000).

Write a solution to find the name, population, and area of the big countries.

Input:
World table:
+-------------+-----------+---------+------------+--------------+
| name        | continent | area    | population | gdp          |
+-------------+-----------+---------+------------+--------------+
| Afghanistan | Asia      | 652230  | 25500100   | 20343000000  |
| Albania     | Europe    | 28748   | 2831741    | 12960000000  |
| Algeria     | Africa    | 2381741 | 37100000   | 188681000000 |
| Andorra     | Europe    | 468     | 78115      | 3712000000   |
| Angola      | Africa    | 1246700 | 20609294   | 100990000000 |
+-------------+-----------+---------+------------+--------------+

Output:
+-------------+------------+---------+
| name        | population | area    |
+-------------+------------+---------+
| Afghanistan | 25500100   | 652230  |
| Algeria     | 37100000   | 2381741 |
+-------------+------------+---------+
```

#### Schema

```sql
drop database sql_50;

create table if not exists world (name varchar(255), continent varchar(255), area int, population int, gdp bigint);

truncate table world;

insert into world (name, continent, area, population, gdp) values ('afghanistan', 'asia', '652230', '25500100', '20343000000');
insert into world (name, continent, area, population, gdp) values ('albania', 'europe', '28748', '2831741', '12960000000');
insert into world (name, continent, area, population, gdp) values ('algeria', 'africa', '2381741', '37100000', '188681000000');
insert into world (name, continent, area, population, gdp) values ('andorra', 'europe', '468', '78115', '3712000000');
insert into world (name, continent, area, population, gdp) values ('angola', 'africa', '1246700', '20609294', '100990000000');
```

### 01148. Article Views 1

#### Statement

```sql
Table: Views

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| article_id    | int     |
| author_id     | int     |
| viewer_id     | int     |
| view_date     | date    |
+---------------+---------+

There is no primary key (column with unique values) for this table, the table may have duplicate rows.

Each row of this table indicates that some viewer viewed an article (written by some author) on some date.

Note that equal author_id and viewer_id indicate the same person.

Write a solution to find all the authors that viewed at least one of their own articles.

Input:
Views table:
+------------+-----------+-----------+------------+
| article_id | author_id | viewer_id | view_date  |
+------------+-----------+-----------+------------+
| 1          | 3         | 5         | 2019-08-01 |
| 1          | 3         | 6         | 2019-08-02 |
| 2          | 7         | 7         | 2019-08-01 |
| 2          | 7         | 6         | 2019-08-02 |
| 4          | 7         | 1         | 2019-07-22 |
| 3          | 4         | 4         | 2019-07-21 |
| 3          | 4         | 4         | 2019-07-21 |
+------------+-----------+-----------+------------+

Output:
+------+
| id   |
+------+
| 4    |
| 7    |
+------+
```

#### Schema

```sql
drop database sql_50;

create table if not exists views (article_id int, author_id int, viewer_id int, view_date date);

truncate table views;

insert into views (article_id, author_id, viewer_id, view_date) values ('1', '3', '5', '2019-08-01');
insert into views (article_id, author_id, viewer_id, view_date) values ('1', '3', '6', '2019-08-02');
insert into views (article_id, author_id, viewer_id, view_date) values ('2', '7', '7', '2019-08-01');
insert into views (article_id, author_id, viewer_id, view_date) values ('2', '7', '6', '2019-08-02');
insert into views (article_id, author_id, viewer_id, view_date) values ('4', '7', '1', '2019-07-22');
insert into views (article_id, author_id, viewer_id, view_date) values ('3', '4', '4', '2019-07-21');
insert into views (article_id, author_id, viewer_id, view_date) values ('3', '4', '4', '2019-07-21');
```

### 01683. Invalid Tweets

#### Statement

```sql
Table: Tweets

+----------------+---------+
| Column Name    | Type    |
+----------------+---------+
| tweet_id       | int     |
| content        | varchar |
+----------------+---------+

tweet_id is the primary key (column with unique values) for this table.

content consists of characters on an American Keyboard, and no other special characters.
This table contains all the tweets in a social media app.

Write a solution to find the IDs of the invalid tweets. The tweet is invalid if the number of characters used in the content of the tweet is strictly greater than 15.

Input:
Tweets table:
+----------+-----------------------------------+
| tweet_id | content                           |
+----------+-----------------------------------+
| 1        | Let us Code                       |
| 2        | More than fifteen chars are here! |
+----------+-----------------------------------+

Output:
+----------+
| tweet_id |
+----------+
| 2        |
+----------+

Explanation:

Tweet 1 has length = 11. It is a valid tweet.

Tweet 2 has length = 33. It is an invalid tweet.
```

#### Schema

```sql
drop database sql_50;

create table if not exists tweets(tweet_id int, content varchar(50));

truncate table tweets;

insert into tweets (tweet_id, content) values ('1', 'let us code');
insert into tweets (tweet_id, content) values ('2', 'more than fifteen chars are here!');
```

## Basic Joins

An introduction to **Join** in SQL

### 01378. Replace Employee ID With The Unique Identifier

#### Statement

```sql
Table: Employees

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| id            | int     |
| name          | varchar |
+---------------+---------+

id is the primary key (column with unique values) for this table.

Each row of this table contains the id and the name of an employee in a company.


Table: EmployeeUNI

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| id            | int     |
| unique_id     | int     |
+---------------+---------+

(id, unique_id) is the primary key (combination of columns with unique values) for this table.

Each row of this table contains the id and the corresponding unique id of an employee in the company.

Write a solution to show the unique ID of each user, If a user does not have a unique ID replace just show null.

Input:
Employees table:
+----+----------+
| id | name     |
+----+----------+
| 1  | Alice    |
| 7  | Bob      |
| 11 | Meir     |
| 90 | Winston  |
| 3  | Jonathan |
+----+----------+

EmployeeUNI table:
+----+-----------+
| id | unique_id |
+----+-----------+
| 3  | 1         |
| 11 | 2         |
| 90 | 3         |
+----+-----------+

Output:
+-----------+----------+
| unique_id | name     |
+-----------+----------+
| null      | Alice    |
| null      | Bob      |
| 2         | Meir     |
| 3         | Winston  |
| 1         | Jonathan |
+-----------+----------+

Explanation:
Alice and Bob do not have a unique ID, We will show null instead.
The unique ID of Meir is 2.
The unique ID of Winston is 3.
The unique ID of Jonathan is 1.
```

#### Schema

```sql
drop database sql_50;

create table if not exists employees (id int, name varchar(20));
create table if not exists employeeuni (id int, unique_id int);

truncate table employees;

insert into employees (id, name) values ('1', 'alice');
insert into employees (id, name) values ('7', 'bob');
insert into employees (id, name) values ('11', 'meir');
insert into employees (id, name) values ('90', 'winston');
insert into employees (id, name) values ('3', 'jonathan');

truncate table employeeuni;

insert into employeeuni (id, unique_id) values ('3', '1');
insert into employeeuni (id, unique_id) values ('11', '2');
insert into employeeuni (id, unique_id) values ('90', '3');
```

### 01068. Product Sales Analysis 1

#### Statement

```sql
Table: Sales

+-------------+-------+
| Column Name | Type  |
+-------------+-------+
| sale_id     | int   |
| product_id  | int   |
| year        | int   |
| quantity    | int   |
| price       | int   |
+-------------+-------+

(sale_id, year) is the primary key (combination of columns with unique values) of this table.

product_id is a foreign key (reference column) to Product table.

Each row of this table shows a sale on the product product_id in a certain year.

Note that the price is per unit.

Table: Product

+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| product_id   | int     |
| product_name | varchar |
+--------------+---------+

product_id is the primary key (column with unique values) of this table.

Each row of this table indicates the product name of each product.

Write a solution to report the product_name, year, and price for each sale_id in the Sales table.

Input:
Sales table:
+---------+------------+------+----------+-------+
| sale_id | product_id | year | quantity | price |
+---------+------------+------+----------+-------+
| 1       | 100        | 2008 | 10       | 5000  |
| 2       | 100        | 2009 | 12       | 5000  |
| 7       | 200        | 2011 | 15       | 9000  |
+---------+------------+------+----------+-------+

Product table:
+------------+--------------+
| product_id | product_name |
+------------+--------------+
| 100        | Nokia        |
| 200        | Apple        |
| 300        | Samsung      |
+------------+--------------+

Output:
+--------------+-------+-------+
| product_name | year  | price |
+--------------+-------+-------+
| Nokia        | 2008  | 5000  |
| Nokia        | 2009  | 5000  |
| Apple        | 2011  | 9000  |
+--------------+-------+-------+

Explanation:
From sale_id = 1, we can conclude that Nokia was sold for 5000 in the year 2008.

From sale_id = 2, we can conclude that Nokia was sold for 5000 in the year 2009.

From sale_id = 7, we can conclude that Apple was sold for 9000 in the year 2011.
```

#### Schema

```sql
drop database sql_50;

create table if not exists sales (sale_id int, product_id int, year int, quantity int, price int);

create table if not exists product (product_id int, product_name varchar(10));

truncate table sales;

insert into sales (sale_id, product_id, year, quantity, price) values ('1', '100', '2008', '10', '5000');

insert into sales (sale_id, product_id, year, quantity, price) values ('2', '100', '2009', '12', '5000');

insert into sales (sale_id, product_id, year, quantity, price) values ('7', '200', '2011', '15', '9000');

truncate table product;

insert into product (product_id, product_name) values ('100', 'nokia');

insert into product (product_id, product_name) values ('200', 'apple');

insert into product (product_id, product_name) values ('300', 'samsung');
```

### 01581. Customer Who Visited But Did Not Make Any Transactions

#### Statement

```sql
Table: Visits

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| visit_id    | int     |
| customer_id | int     |
+-------------+---------+

visit_id is the column with unique values for this table.

This table contains information about the customers who visited the mall.

Table: Transactions

+----------------+---------+
| Column Name    | Type    |
+----------------+---------+
| transaction_id | int     |
| visit_id       | int     |
| amount         | int     |
+----------------+---------+

transaction_id is column with unique values for this table.

This table contains information about the transactions made during the visit_id.


Write a solution to find the IDs of the users who visited without making any transactions and the number of times they made these types of visits.

Input:
Visits
+----------+-------------+
| visit_id | customer_id |
+----------+-------------+
| 1        | 23          |
| 2        | 9           |
| 4        | 30          |
| 5        | 54          |
| 6        | 96          |
| 7        | 54          |
| 8        | 54          |
+----------+-------------+

Transactions
+----------------+----------+--------+
| transaction_id | visit_id | amount |
+----------------+----------+--------+
| 2              | 5        | 310    |
| 3              | 5        | 300    |
| 9              | 5        | 200    |
| 12             | 1        | 910    |
| 13             | 2        | 970    |
+----------------+----------+--------+

Output:
+-------------+----------------+
| customer_id | count_no_trans |
+-------------+----------------+
| 54          | 2              |
| 30          | 1              |
| 96          | 1              |
+-------------+----------------+

Explanation:
Customer with id = 23 visited the mall once and made one transaction during the visit with id = 12.

Customer with id = 9 visited the mall once and made one transaction during the visit with id = 13.

Customer with id = 30 visited the mall once and did not make any transactions.

Customer with id = 54 visited the mall three times. During 2 visits they did not make any transactions, and during one visit they made 3 transactions.

Customer with id = 96 visited the mall once and did not make any transactions.

As we can see, users with IDs 30 and 96 visited the mall one time without making any transactions. Also, user 54 visited the mall twice and did not make any transactions.
```

#### Schema

```sql
drop database sql_50;

create table if not exists visits(visit_id int, customer_id int);

create table if not exists transactions(transaction_id int, visit_id int, amount int);

truncate table visits;

insert into visits (visit_id, customer_id) values ('1', '23');
insert into visits (visit_id, customer_id) values ('2', '9');
insert into visits (visit_id, customer_id) values ('4', '30');
insert into visits (visit_id, customer_id) values ('5', '54');
insert into visits (visit_id, customer_id) values ('6', '96');
insert into visits (visit_id, customer_id) values ('7', '54');
insert into visits (visit_id, customer_id) values ('8', '54');

truncate table transactions;

insert into transactions (transaction_id, visit_id, amount) values ('2', '5', '310');
insert into transactions (transaction_id, visit_id, amount) values ('3', '5', '300');
insert into transactions (transaction_id, visit_id, amount) values ('9', '5', '200');
insert into transactions (transaction_id, visit_id, amount) values ('12', '1', '910');
insert into transactions (transaction_id, visit_id, amount) values ('13', '2', '970');
```

### 00197. Rising Temperature

#### Statement

```sql
Table: Weather

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| id            | int     |
| recordDate    | date    |
| temperature   | int     |
+---------------+---------+

id is the column with unique values for this table.

There are no different rows with the same recordDate.

This table contains information about the temperature on a certain day.

Write a solution to find all dates id with higher temperatures compared to its previous dates (yesterday).

Input:
Weather table:
+----+------------+-------------+
| id | recordDate | temperature |
+----+------------+-------------+
| 1  | 2015-01-01 | 10          |
| 2  | 2015-01-02 | 25          |
| 3  | 2015-01-03 | 20          |
| 4  | 2015-01-04 | 30          |
+----+------------+-------------+

Output:
+----+
| id |
+----+
| 2  |
| 4  |
+----+

Explanation:

In 2015-01-02, the temperature was higher than the previous day (10 -> 25).

In 2015-01-04, the temperature was higher than the previous day (20 -> 30).
```

#### Schema

```sql
drop database sql_50;

create table if not exists weather (id int, recorddate date, temperature int);

truncate table weather;

insert into weather (id, recorddate, temperature) values ('1', '2015-01-01', '10');
insert into weather (id, recorddate, temperature) values ('2', '2015-01-02', '25');
insert into weather (id, recorddate, temperature) values ('3', '2015-01-03', '20');
insert into weather (id, recorddate, temperature) values ('4', '2015-01-04', '30');
```

### 01661. Average Time of Process Per Machine

#### Statement

```sql
Table: Activity

+----------------+---------+
| Column Name    | Type    |
+----------------+---------+
| machine_id     | int     |
| process_id     | int     |
| activity_type  | enum    |
| timestamp      | float   |
+----------------+---------+

The table shows the user activities for a factory website.

(machine_id, process_id, activity_type) is the primary key (combination of columns with unique values) of this table.

machine_id is the ID of a machine.

process_id is the ID of a process running on the machine with ID machine_id.
activity_type is an ENUM (category) of type ('start', 'end').

timestamp is a float representing the current time in seconds.

'start' means the machine starts the process at the given timestamp and 'end' means the machine ends the process at the given timestamp.

The 'start' timestamp will always be before the 'end' timestamp for every (machine_id, process_id) pair.

It is guaranteed that each (machine_id, process_id) pair has a 'start' and 'end' timestamp.

There is a factory website that has several machines each running the same number of processes. Write a solution to find the average time each machine takes to complete a process.

The time to complete a process is the 'end' timestamp minus the 'start' timestamp. The average time is calculated by the total time to complete every process on the machine divided by the number of processes that were run.

The resulting table should have the machine_id along with the average time as processing_time, which should be rounded to 3 decimal places.

Input:
Activity table:
+------------+------------+---------------+-----------+
| machine_id | process_id | activity_type | timestamp |
+------------+------------+---------------+-----------+
| 0          | 0          | start         | 0.712     |
| 0          | 0          | end           | 1.520     |
| 0          | 1          | start         | 3.140     |
| 0          | 1          | end           | 4.120     |
| 1          | 0          | start         | 0.550     |
| 1          | 0          | end           | 1.550     |
| 1          | 1          | start         | 0.430     |
| 1          | 1          | end           | 1.420     |
| 2          | 0          | start         | 4.100     |
| 2          | 0          | end           | 4.512     |
| 2          | 1          | start         | 2.500     |
| 2          | 1          | end           | 5.000     |
+------------+------------+---------------+-----------+

Output:
+------------+-----------------+
| machine_id | processing_time |
+------------+-----------------+
| 0          | 0.894           |
| 1          | 0.995           |
| 2          | 1.456           |
+------------+-----------------+

Explanation:

There are 3 machines running 2 processes each.

Machine 0's average time is ((1.520 - 0.712) + (4.120 - 3.140)) / 2 = 0.894

Machine 1's average time is ((1.550 - 0.550) + (1.420 - 0.430)) / 2 = 0.995

Machine 2's average time is ((4.512 - 4.100) + (5.000 - 2.500)) / 2 = 1.456
```

#### Schema

```sql
drop database sql_50;

create table if not exists activity (machine_id int, process_id int, activity_type enum('start', 'end'), timestamp float);

truncate table activity;

insert into activity (machine_id, process_id, activity_type, timestamp) values ('0', '0', 'start', '0.712');
insert into activity (machine_id, process_id, activity_type, timestamp) values ('0', '0', 'end', '1.52');
insert into activity (machine_id, process_id, activity_type, timestamp) values ('0', '1', 'start', '3.14');
insert into activity (machine_id, process_id, activity_type, timestamp) values ('0', '1', 'end', '4.12');
insert into activity (machine_id, process_id, activity_type, timestamp) values ('1', '0', 'start', '0.55');
insert into activity (machine_id, process_id, activity_type, timestamp) values ('1', '0', 'end', '1.55');
insert into activity (machine_id, process_id, activity_type, timestamp) values ('1', '1', 'start', '0.43');
insert into activity (machine_id, process_id, activity_type, timestamp) values ('1', '1', 'end', '1.42');
insert into activity (machine_id, process_id, activity_type, timestamp) values ('2', '0', 'start', '4.1');
insert into activity (machine_id, process_id, activity_type, timestamp) values ('2', '0', 'end', '4.512');
insert into activity (machine_id, process_id, activity_type, timestamp) values ('2', '1', 'start', '2.5');
insert into activity (machine_id, process_id, activity_type, timestamp) values ('2', '1', 'end', '5');
```

### 00577. Employee Bonus

#### Statement

```sql
Table: Employee

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| empId       | int     |
| name        | varchar |
| supervisor  | int     |
| salary      | int     |
+-------------+---------+

empId is the column with unique values for this table.

Each row of this table indicates the name and the ID of an employee in addition to their salary and the id of their manager.

Table: Bonus

+-------------+------+
| Column Name | Type |
+-------------+------+
| empId       | int  |
| bonus       | int  |
+-------------+------+

empId is the column of unique values for this table.

empId is a foreign key (reference column) to empId from the Employee table.

Each row of this table contains the id of an employee and their respective bonus.

Write a solution to report the name and bonus amount of each employee with a bonus less than 1000.

Input:
Employee table:
+-------+--------+------------+--------+
| empId | name   | supervisor | salary |
+-------+--------+------------+--------+
| 3     | Brad   | null       | 4000   |
| 1     | John   | 3          | 1000   |
| 2     | Dan    | 3          | 2000   |
| 4     | Thomas | 3          | 4000   |
+-------+--------+------------+--------+

Bonus table:
+-------+-------+
| empId | bonus |
+-------+-------+
| 2     | 500   |
| 4     | 2000  |
+-------+-------+

Output:
+------+-------+
| name | bonus |
+------+-------+
| Brad | null  |
| John | null  |
| Dan  | 500   |
+------+-------+
```

#### Schema

```sql
drop database sql_50;

create table if not exists employee (empid int, name varchar(255), supervisor int, salary int);
create table if not exists bonus (empid int, bonus int);

truncate table employee;

insert into employee (empid, name, supervisor, salary) values ('3', 'brad', null, '4000');
insert into employee (empid, name, supervisor, salary) values ('1', 'john', '3', '1000');
insert into employee (empid, name, supervisor, salary) values ('2', 'dan', '3', '2000');
insert into employee (empid, name, supervisor, salary) values ('4', 'thomas', '3', '4000');

truncate table bonus;

insert into bonus (empid, bonus) values ('2', '500');
insert into bonus (empid, bonus) values ('4', '2000');
```

### 01280. Students and Examinations

#### Statement

```sql
Table: Students

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| student_id    | int     |
| student_name  | varchar |
+---------------+---------+

student_id is the primary key (column with unique values) for this table.

Each row of this table contains the ID and the name of one student in the school.

Table: Subjects

+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| subject_name | varchar |
+--------------+---------+

subject_name is the primary key (column with unique values) for this table.

Each row of this table contains the name of one subject in the school.

Table: Examinations

+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| student_id   | int     |
| subject_name | varchar |
+--------------+---------+

There is no primary key (column with unique values) for this table. It may contain duplicates.

Each student from the Students table takes every course from the Subjects table.

Each row of this table indicates that a student with ID student_id attended the exam of subject_name.

Write a solution to find the number of times each student attended each exam.

Input:
Students table:
+------------+--------------+
| student_id | student_name |
+------------+--------------+
| 1          | Alice        |
| 2          | Bob          |
| 13         | John         |
| 6          | Alex         |
+------------+--------------+

Subjects table:
+--------------+
| subject_name |
+--------------+
| Math         |
| Physics      |
| Programming  |
+--------------+

Examinations table:
+------------+--------------+
| student_id | subject_name |
+------------+--------------+
| 1          | Math         |
| 1          | Physics      |
| 1          | Programming  |
| 2          | Programming  |
| 1          | Physics      |
| 1          | Math         |
| 13         | Math         |
| 13         | Programming  |
| 13         | Physics      |
| 2          | Math         |
| 1          | Math         |
+------------+--------------+

Output:
+------------+--------------+--------------+----------------+
| student_id | student_name | subject_name | attended_exams |
+------------+--------------+--------------+----------------+
| 1          | Alice        | Math         | 3              |
| 1          | Alice        | Physics      | 2              |
| 1          | Alice        | Programming  | 1              |
| 2          | Bob          | Math         | 1              |
| 2          | Bob          | Physics      | 0              |
| 2          | Bob          | Programming  | 1              |
| 6          | Alex         | Math         | 0              |
| 6          | Alex         | Physics      | 0              |
| 6          | Alex         | Programming  | 0              |
| 13         | John         | Math         | 1              |
| 13         | John         | Physics      | 1              |
| 13         | John         | Programming  | 1              |
+------------+--------------+--------------+----------------+

Explanation:

The result table should contain all students and all subjects.

Alice attended the Math exam 3 times, the Physics exam 2 times, and the Programming exam 1 time.

Bob attended the Math exam 1 time, the Programming exam 1 time, and did not attend the Physics exam.

Alex did not attend any exams.

John attended the Math exam 1 time, the Physics exam 1 time, and the Programming exam 1 time.
```

#### Schema

```sql
drop database sql_50;

create table if not exists students (student_id int, student_name varchar(20));
create table if not exists subjects (subject_name varchar(20));
create table if not exists examinations (student_id int, subject_name varchar(20));

truncate table students;

insert into students (student_id, student_name) values ('1', 'alice');
insert into students (student_id, student_name) values ('2', 'bob');
insert into students (student_id, student_name) values ('13', 'john');
insert into students (student_id, student_name) values ('6', 'alex');

truncate table subjects;

insert into subjects (subject_name) values ('math');
insert into subjects (subject_name) values ('physics');
insert into subjects (subject_name) values ('programming');

truncate table examinations;

insert into examinations (student_id, subject_name) values ('1', 'math');
insert into examinations (student_id, subject_name) values ('1', 'physics');
insert into examinations (student_id, subject_name) values ('1', 'programming');
insert into examinations (student_id, subject_name) values ('2', 'programming');
insert into examinations (student_id, subject_name) values ('1', 'physics');
insert into examinations (student_id, subject_name) values ('1', 'math');
insert into examinations (student_id, subject_name) values ('13', 'math');
insert into examinations (student_id, subject_name) values ('13', 'programming');
insert into examinations (student_id, subject_name) values ('13', 'physics');
insert into examinations (student_id, subject_name) values ('2', 'math');
insert into examinations (student_id, subject_name) values ('1', 'math');
```

### 00570. Managers with atleast 5 direct Reports

#### Statement

```sql
Table: Employee

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| name        | varchar |
| department  | varchar |
| managerId   | int     |
+-------------+---------+

id is the primary key (column with unique values) for this table.

Each row of this table indicates the name of an employee, their department, and the id of their manager.

If managerId is null, then the employee does not have a manager.

No employee will be the manager of themself.

Write a solution to find managers with at least five direct reports.

Input:
Employee table:
+-----+-------+------------+-----------+
| id  | name  | department | managerId |
+-----+-------+------------+-----------+
| 101 | John  | A          | null      |
| 102 | Dan   | A          | 101       |
| 103 | James | A          | 101       |
| 104 | Amy   | A          | 101       |
| 105 | Anne  | A          | 101       |
| 106 | Ron   | B          | 101       |
+-----+-------+------------+-----------+

Output:
+------+
| name |
+------+
| John |
+------+
```

#### Schema

```sql
drop database sql_50;

create table if not exists employee (id int, name varchar(255), department varchar(255), managerid int);

truncate table employee;

insert into employee (id, name, department, managerid) values ('101', 'john', 'a', null);
insert into employee (id, name, department, managerid) values ('102', 'dan', 'a', '101');
insert into employee (id, name, department, managerid) values ('103', 'james', 'a', '101');
insert into employee (id, name, department, managerid) values ('104', 'amy', 'a', '101');
insert into employee (id, name, department, managerid) values ('105', 'anne', 'a', '101');
insert into employee (id, name, department, managerid) values ('106', 'ron', 'b', '101');
```

### 01934. Confirmation Rate

#### Statement

```sql
Table: Signups

+----------------+----------+
| Column Name    | Type     |
+----------------+----------+
| user_id        | int      |
| time_stamp     | datetime |
+----------------+----------+

user_id is the column of unique values for this table.

Each row contains information about the signup time for the user with ID user_id.


Table: Confirmations

+----------------+----------+
| Column Name    | Type     |
+----------------+----------+
| user_id        | int      |
| time_stamp     | datetime |
| action         | ENUM     |
+----------------+----------+

(user_id, time_stamp) is the primary key (combination of columns with unique values) for this table.

user_id is a foreign key (reference column) to the Signups table.

action is an ENUM (category) of the type ('confirmed', 'timeout').

Each row of this table indicates that the user with ID user_id requested a confirmation message at time_stamp and that confirmation message was either confirmed ('confirmed') or expired without confirming ('timeout').

The confirmation rate of a user is the number of 'confirmed' messages divided by the total number of requested confirmation messages. The confirmation rate of a user that did not request any confirmation messages is 0. Round the confirmation rate to two decimal places.

Write a solution to find the confirmation rate of each user.

Input:
Signups table:
+---------+---------------------+
| user_id | time_stamp          |
+---------+---------------------+
| 3       | 2020-03-21 10:16:13 |
| 7       | 2020-01-04 13:57:59 |
| 2       | 2020-07-29 23:09:44 |
| 6       | 2020-12-09 10:39:37 |
+---------+---------------------+

Confirmations table:
+---------+---------------------+-----------+
| user_id | time_stamp          | action    |
+---------+---------------------+-----------+
| 3       | 2021-01-06 03:30:46 | timeout   |
| 3       | 2021-07-14 14:00:00 | timeout   |
| 7       | 2021-06-12 11:57:29 | confirmed |
| 7       | 2021-06-13 12:58:28 | confirmed |
| 7       | 2021-06-14 13:59:27 | confirmed |
| 2       | 2021-01-22 00:00:00 | confirmed |
| 2       | 2021-02-28 23:59:59 | timeout   |
+---------+---------------------+-----------+

Output:
+---------+-------------------+
| user_id | confirmation_rate |
+---------+-------------------+
| 6       | 0.00              |
| 3       | 0.00              |
| 7       | 1.00              |
| 2       | 0.50              |
+---------+-------------------+

Explanation:

User 6 did not request any confirmation messages. The confirmation rate is 0.

User 3 made 2 requests and both timed out. The confirmation rate is 0.

User 7 made 3 requests and all were confirmed. The confirmation rate is 1.

User 2 made 2 requests where one was confirmed and the other timed out. The confirmation rate is 1 / 2 = 0.5.
```

#### Schema

```sql
drop database sql_50;

create table if not exists signups (user_id int, time_stamp datetime);
create table if not exists confirmations (user_id int, time_stamp datetime, action enum('confirmed','timeout'));

truncate table signups;

insert into signups (user_id, time_stamp) values ('3', '2020-03-21 10:16:13');
insert into signups (user_id, time_stamp) values ('7', '2020-01-04 13:57:59');
insert into signups (user_id, time_stamp) values ('2', '2020-07-29 23:09:44');
insert into signups (user_id, time_stamp) values ('6', '2020-12-09 10:39:37');

truncate table confirmations;

insert into confirmations (user_id, time_stamp, action) values ('3', '2021-01-06 03:30:46', 'timeout');
insert into confirmations (user_id, time_stamp, action) values ('3', '2021-07-14 14:00:00', 'timeout');
insert into confirmations (user_id, time_stamp, action) values ('7', '2021-06-12 11:57:29', 'confirmed');
insert into confirmations (user_id, time_stamp, action) values ('7', '2021-06-13 12:58:28', 'confirmed');
insert into confirmations (user_id, time_stamp, action) values ('7', '2021-06-14 13:59:27', 'confirmed');
insert into confirmations (user_id, time_stamp, action) values ('2', '2021-01-22 00:00:00', 'confirmed');
insert into confirmations (user_id, time_stamp, action) values ('2', '2021-02-28 23:59:59', 'timeout');
```

## Basic Aggregate Functions

An introduction to **Aggregate Functions** in SQL

## Sorting and Grouping

SQL queries to arrange rows based on a single or multiple columns

## Advanced Select and Joins

Moving towards **Advanced Select and Join** queries

## Subqueries

Introduction to **Subqueries**

## Advanced String Functions / Regex / Clause

Transforming data while quering using **String Functions / Regex / Clause**

## Author

[Arsalan Ansari](https://www.github.com/madebyarsalan)
