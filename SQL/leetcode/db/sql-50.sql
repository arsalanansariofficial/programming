drop database if exists sql_50;

create database sql_50;

use sql_50;

create table if not exists products (product_id int, low_fats enum('y', 'n'), recyclable enum('y','n'));

truncate table products;

insert into products (product_id, low_fats, recyclable) values ('0', 'y', 'n');
insert into products (product_id, low_fats, recyclable) values ('1', 'y', 'y');
insert into products (product_id, low_fats, recyclable) values ('2', 'n', 'y');
insert into products (product_id, low_fats, recyclable) values ('3', 'y', 'y');
insert into products (product_id, low_fats, recyclable) values ('4', 'n', 'n');

create table if not exists customer (id int, name varchar(25), referee_id int);

truncate table customer;

insert into customer (id, name, referee_id) values ('1', 'will', null);
insert into customer (id, name, referee_id) values ('2', 'jane', null);
insert into customer (id, name, referee_id) values ('3', 'alex', '2');
insert into customer (id, name, referee_id) values ('4', 'bill', null);
insert into customer (id, name, referee_id) values ('5', 'zack', '1');
insert into customer (id, name, referee_id) values ('6', 'mark', '2');

create table if not exists world (name varchar(255), continent varchar(255), area int, population int, gdp bigint);

truncate table world;

insert into world (name, continent, area, population, gdp) values ('afghanistan', 'asia', '652230', '25500100', '20343000000');
insert into world (name, continent, area, population, gdp) values ('albania', 'europe', '28748', '2831741', '12960000000');
insert into world (name, continent, area, population, gdp) values ('algeria', 'africa', '2381741', '37100000', '188681000000');
insert into world (name, continent, area, population, gdp) values ('andorra', 'europe', '468', '78115', '3712000000');
insert into world (name, continent, area, population, gdp) values ('angola', 'africa', '1246700', '20609294', '100990000000');

create table if not exists views (article_id int, author_id int, viewer_id int, view_date date);

truncate table views;

insert into views (article_id, author_id, viewer_id, view_date) values ('1', '3', '5', '2019-08-01');
insert into views (article_id, author_id, viewer_id, view_date) values ('1', '3', '6', '2019-08-02');
insert into views (article_id, author_id, viewer_id, view_date) values ('2', '7', '7', '2019-08-01');
insert into views (article_id, author_id, viewer_id, view_date) values ('2', '7', '6', '2019-08-02');
insert into views (article_id, author_id, viewer_id, view_date) values ('4', '7', '1', '2019-07-22');
insert into views (article_id, author_id, viewer_id, view_date) values ('3', '4', '4', '2019-07-21');
insert into views (article_id, author_id, viewer_id, view_date) values ('3', '4', '4', '2019-07-21');

create table if not exists tweets(tweet_id int, content varchar(50));

truncate table tweets;

insert into tweets (tweet_id, content) values ('1', 'let us code');
insert into tweets (tweet_id, content) values ('2', 'more than fifteen chars are here!');

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

create table if not exists weather (id int, recorddate date, temperature int);

truncate table weather;

insert into weather (id, recorddate, temperature) values ('1', '2015-01-01', '10');
insert into weather (id, recorddate, temperature) values ('2', '2015-01-02', '25');
insert into weather (id, recorddate, temperature) values ('3', '2015-01-03', '20');
insert into weather (id, recorddate, temperature) values ('4', '2015-01-04', '30');

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

create table if not exists employee (id int, name varchar(255), department varchar(255), managerid int);

truncate table employee;

insert into employee (id, name, department, managerid) values ('101', 'john', 'a', null);
insert into employee (id, name, department, managerid) values ('102', 'dan', 'a', '101');
insert into employee (id, name, department, managerid) values ('103', 'james', 'a', '101');
insert into employee (id, name, department, managerid) values ('104', 'amy', 'a', '101');
insert into employee (id, name, department, managerid) values ('105', 'anne', 'a', '101');
insert into employee (id, name, department, managerid) values ('106', 'ron', 'b', '101');