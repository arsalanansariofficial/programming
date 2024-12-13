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

## Basic Joins

An introduction to **Join** in SQL

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
