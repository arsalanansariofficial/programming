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

create table if not exists prices (product_id int, start_date date, end_date date, price int);
create table if not exists unitssold (product_id int, purchase_date date, units int);

truncate table prices;

insert into prices (product_id, start_date, end_date, price) values ('1', '2019-02-17', '2019-02-28', '5');
insert into prices (product_id, start_date, end_date, price) values ('1', '2019-03-01', '2019-03-22', '20');
insert into prices (product_id, start_date, end_date, price) values ('2', '2019-02-01', '2019-02-20', '15');
insert into prices (product_id, start_date, end_date, price) values ('2', '2019-02-21', '2019-03-31', '30');

truncate table unitssold;

insert into unitssold (product_id, purchase_date, units) values ('1', '2019-02-25', '100');
insert into unitssold (product_id, purchase_date, units) values ('1', '2019-03-01', '15');
insert into unitssold (product_id, purchase_date, units) values ('2', '2019-02-10', '200');
insert into unitssold (product_id, purchase_date, units) values ('2', '2019-03-22', '30');

create table if not exists project (project_id int, empid int);
create table if not exists employee (empid int, name varchar(255), supervisor int, salary int, experience_years int);

truncate table project;

insert into project (project_id, empid) values ('1', '1');
insert into project (project_id, empid) values ('1', '2');
insert into project (project_id, empid) values ('1', '3');
insert into project (project_id, empid) values ('2', '1');
insert into project (project_id, empid) values ('2', '4');

truncate table employee;

insert into employee (empid, name, experience_years) values ('2', 'ali', '2');
insert into employee (empid, name, experience_years) values ('4', 'doe', '2');
insert into employee (empid, name, experience_years) values ('3', 'john', '1');
insert into employee (empid, name, experience_years) values ('1', 'khaled', '3');

create table if not exists register (contest_id int, user_id int);
create table if not exists users (user_id int, user_name varchar(20));

truncate table users;

insert into users (user_id, user_name) values ('2', 'bob');
insert into users (user_id, user_name) values ('7', 'alex');
insert into users (user_id, user_name) values ('6', 'alice');

truncate table register;

insert into register (contest_id, user_id) values ('215', '6');
insert into register (contest_id, user_id) values ('209', '2');
insert into register (contest_id, user_id) values ('208', '2');
insert into register (contest_id, user_id) values ('210', '6');
insert into register (contest_id, user_id) values ('208', '6');
insert into register (contest_id, user_id) values ('209', '7');
insert into register (contest_id, user_id) values ('209', '6');
insert into register (contest_id, user_id) values ('215', '7');
insert into register (contest_id, user_id) values ('208', '7');
insert into register (contest_id, user_id) values ('210', '2');
insert into register (contest_id, user_id) values ('207', '2');
insert into register (contest_id, user_id) values ('210', '7');

create table if not exists queries (query_name varchar(30), result varchar(50), position int, rating int);

truncate table queries;

insert into queries (query_name, result, position, rating) values ('dog', 'mule', '200', '1');
insert into queries (query_name, result, position, rating) values ('cat', 'sphynx', '7', '4');
insert into queries (query_name, result, position, rating) values ('cat', 'shirazi', '5', '2');
insert into queries (query_name, result, position, rating) values ('cat', 'siamese', '3', '3');
insert into queries (query_name, result, position, rating) values ('dog', 'german shepherd', '2', '5');
insert into queries (query_name, result, position, rating) values ('dog', 'golden retriever', '1', '5');

create table if not exists transactions (id int, country varchar(4), state enum('approved', 'declined'), amount int, trans_date date);

truncate table transactions;

insert into transactions (id, country, state, amount, trans_date) values ('121', 'us', 'approved', '1000', '2018-12-18');
insert into transactions (id, country, state, amount, trans_date) values ('122', 'us', 'declined', '2000', '2018-12-19');
insert into transactions (id, country, state, amount, trans_date) values ('123', 'us', 'approved', '2000', '2019-01-01');
insert into transactions (id, country, state, amount, trans_date) values ('124', 'de', 'approved', '2000', '2019-01-07');

create table if not exists delivery (delivery_id int, customer_id int, order_date date, customer_pref_delivery_date date);

truncate table delivery;

insert into delivery (delivery_id, customer_id, order_date, customer_pref_delivery_date) values ('1', '1', '2019-08-01', '2019-08-02');
insert into delivery (delivery_id, customer_id, order_date, customer_pref_delivery_date) values ('2', '2', '2019-08-02', '2019-08-02');
insert into delivery (delivery_id, customer_id, order_date, customer_pref_delivery_date) values ('3', '1', '2019-08-11', '2019-08-12');
insert into delivery (delivery_id, customer_id, order_date, customer_pref_delivery_date) values ('4', '3', '2019-08-24', '2019-08-24');
insert into delivery (delivery_id, customer_id, order_date, customer_pref_delivery_date) values ('5', '3', '2019-08-21', '2019-08-22');
insert into delivery (delivery_id, customer_id, order_date, customer_pref_delivery_date) values ('6', '2', '2019-08-11', '2019-08-13');
insert into delivery (delivery_id, customer_id, order_date, customer_pref_delivery_date) values ('7', '4', '2019-08-09', '2019-08-09');

create table if not exists activity (player_id int, device_id int, event_date date, games_played int);

truncate table activity;

insert into activity (player_id, device_id, event_date, games_played) values ('1', '2', '2016-03-01', '5');
insert into activity (player_id, device_id, event_date, games_played) values ('1', '2', '2016-03-02', '6');
insert into activity (player_id, device_id, event_date, games_played) values ('2', '3', '2017-06-25', '1');
insert into activity (player_id, device_id, event_date, games_played) values ('3', '1', '2016-03-02', '0');
insert into activity (player_id, device_id, event_date, games_played) values ('3', '4', '2018-07-03', '5');

truncate table teacher;

insert into teacher (teacher_id, subject_id, dept_id) values ('1', '2', '3');
insert into teacher (teacher_id, subject_id, dept_id) values ('1', '2', '4');
insert into teacher (teacher_id, subject_id, dept_id) values ('1', '3', '3');
insert into teacher (teacher_id, subject_id, dept_id) values ('2', '1', '1');
insert into teacher (teacher_id, subject_id, dept_id) values ('2', '2', '1');
insert into teacher (teacher_id, subject_id, dept_id) values ('2', '3', '1');
insert into teacher (teacher_id, subject_id, dept_id) values ('2', '4', '1');

drop table if exists activity;

create table if not exists activity (user_id int, session_id int, activity_date date, activity_type enum('open_session', 'end_session', 'scroll_down', 'send_message'));

truncate table activity;

insert into activity (user_id, session_id, activity_date, activity_type) values ('1', '1', '2019-07-20', 'scroll_down');
insert into activity (user_id, session_id, activity_date, activity_type) values ('1', '1', '2019-07-20', 'end_session');
insert into activity (user_id, session_id, activity_date, activity_type) values ('2', '4', '2019-07-21', 'end_session');
insert into activity (user_id, session_id, activity_date, activity_type) values ('3', '2', '2019-07-21', 'end_session');
insert into activity (user_id, session_id, activity_date, activity_type) values ('4', '3', '2019-06-25', 'end_session');
insert into activity (user_id, session_id, activity_date, activity_type) values ('1', '1', '2019-07-20', 'open_session');
insert into activity (user_id, session_id, activity_date, activity_type) values ('2', '4', '2019-07-20', 'open_session');
insert into activity (user_id, session_id, activity_date, activity_type) values ('2', '4', '2019-07-21', 'send_message');
insert into activity (user_id, session_id, activity_date, activity_type) values ('3', '2', '2019-07-21', 'open_session');
insert into activity (user_id, session_id, activity_date, activity_type) values ('3', '2', '2019-07-21', 'send_message');
insert into activity (user_id, session_id, activity_date, activity_type) values ('4', '3', '2019-06-25', 'open_session');

create table if not exists sales (sale_id int, product_id int, year int, quantity int, price int);

truncate table sales;

insert into sales (sale_id, product_id, year, quantity, price) values ('1', '100', '2008', '10', '5000');
insert into sales (sale_id, product_id, year, quantity, price) values ('2', '100', '2009', '12', '5000');
insert into sales (sale_id, product_id, year, quantity, price) values ('7', '200', '2011', '15', '9000');

create table if not exists courses (student varchar(255), class varchar(255));

truncate table courses;

insert into courses (student, class) values ('a', 'math');
insert into courses (student, class) values ('c', 'math');
insert into courses (student, class) values ('e', 'math');
insert into courses (student, class) values ('g', 'math');
insert into courses (student, class) values ('h', 'math');
insert into courses (student, class) values ('i', 'math');
insert into courses (student, class) values ('b', 'english');
insert into courses (student, class) values ('d', 'biology');
insert into courses (student, class) values ('f', 'computer');

create table if not exists followers(user_id int, follower_id int)

truncate table followers;

insert into followers (user_id, follower_id) values ('0', '1');
insert into followers (user_id, follower_id) values ('1', '0');
insert into followers (user_id, follower_id) values ('2', '0');
insert into followers (user_id, follower_id) values ('2', '1');

create table if not exists mynumbers (num int);

truncate table mynumbers;

insert into mynumbers (num) values ('8');
insert into mynumbers (num) values ('8');
insert into mynumbers (num) values ('3');
insert into mynumbers (num) values ('3');
insert into mynumbers (num) values ('1');
insert into mynumbers (num) values ('4');
insert into mynumbers (num) values ('5');
insert into mynumbers (num) values ('6');

create table product (product_key int);
create table if not exists customer (customer_id int, product_key int);

truncate table product;
truncate table customer;

insert into product (product_key) values ('5');
insert into product (product_key) values ('6');

insert into customer (customer_id, product_key) values ('1', '5');
insert into customer (customer_id, product_key) values ('2', '6');
insert into customer (customer_id, product_key) values ('3', '5');
insert into customer (customer_id, product_key) values ('3', '6');
insert into customer (customer_id, product_key) values ('1', '6');

create table if not exists employees(employee_id int, name varchar(20), reports_to int, age int);

truncate table employees

insert into employees (employee_id, name, reports_to, age) values ('4', 'bob', '9', '36');
insert into employees (employee_id, name, reports_to, age) values ('6', 'alice', '9', '41');
insert into employees (employee_id, name, reports_to, age) values ('9', 'hercy', null, '43');
insert into employees (employee_id, name, reports_to, age) values ('2', 'winston', null, '37');

drop table if exists employee;

create table if not exists employee (employee_id int, department_id int, primary_flag enum('y','n'));

truncate table employee;

insert into employee (employee_id, department_id, primary_flag) values ('1', '1', 'n');
insert into employee (employee_id, department_id, primary_flag) values ('2', '1', 'y');
insert into employee (employee_id, department_id, primary_flag) values ('2', '2', 'n');
insert into employee (employee_id, department_id, primary_flag) values ('3', '3', 'n');
insert into employee (employee_id, department_id, primary_flag) values ('4', '2', 'n');
insert into employee (employee_id, department_id, primary_flag) values ('4', '3', 'y');
insert into employee (employee_id, department_id, primary_flag) values ('4', '4', 'n');

create table if not exists triangle (x int, y int, z int);

truncate table triangle;

insert into triangle (x, y, z) values ('13', '15', '30');
insert into triangle (x, y, z) values ('10', '20', '15');

create table if not exists logs (id int, num int);

truncate table logs;

insert into logs (id, num) values ('1', '1');
insert into logs (id, num) values ('2', '1');
insert into logs (id, num) values ('3', '1');
insert into logs (id, num) values ('4', '2');
insert into logs (id, num) values ('5', '1');
insert into logs (id, num) values ('6', '2');
insert into logs (id, num) values ('7', '2');

drop table if exists products;

create table if not exists products (product_id int, new_price int, change_date date);

truncate table products;

insert into products (product_id, new_price, change_date) values ('1', '20', '2019-08-14');
insert into products (product_id, new_price, change_date) values ('2', '50', '2019-08-14');
insert into products (product_id, new_price, change_date) values ('1', '30', '2019-08-15');
insert into products (product_id, new_price, change_date) values ('1', '35', '2019-08-16');
insert into products (product_id, new_price, change_date) values ('2', '65', '2019-08-17');
insert into products (product_id, new_price, change_date) values ('3', '20', '2019-08-18');

create table if not exists queue (person_id int, person_name varchar(30), weight int, turn int);

truncate table queue;

insert into queue (person_id, person_name, weight, turn) values ('4', 'bob', '175', '5');
insert into queue (person_id, person_name, weight, turn) values ('3', 'alex', '350', '2');
insert into queue (person_id, person_name, weight, turn) values ('5', 'alice', '250', '1');
insert into queue (person_id, person_name, weight, turn) values ('2', 'marie', '200', '4');
insert into queue (person_id, person_name, weight, turn) values ('1', 'winston', '500', '6');
insert into queue (person_id, person_name, weight, turn) values ('6', 'john cena', '400', '3');

create table if not exists accounts (account_id int, income int);

truncate table accounts;

insert into accounts (account_id, income) values ('2', '12747');
insert into accounts (account_id, income) values ('8', '87709');
insert into accounts (account_id, income) values ('6', '91796');
insert into accounts (account_id, income) values ('3', '108939');

create table if not exists employees (employee_id int, name varchar(20), manager_id int, salary int);

drop table if exists employees;

truncate table employees;

insert into employees (employee_id, name, manager_id, salary) values ('3', 'mila', '9', '60301');
insert into employees (employee_id, name, manager_id, salary) values ('1', 'kalel', '11', '21241');
insert into employees (employee_id, name, manager_id, salary) values ('13', 'emery', null, '67084');
insert into employees (employee_id, name, manager_id, salary) values ('11', 'joziah', '6', '28485');
insert into employees (employee_id, name, manager_id, salary) values ('9', 'mikaela', null, '50937');
insert into employees (employee_id, name, manager_id, salary) values ('12', 'antonella', null, '31000');

create table if not exists seat (id int, student varchar(255));

truncate table seat;

insert into seat (id, student) values ('1', 'abbot');
insert into seat (id, student) values ('2', 'doris');
insert into seat (id, student) values ('4', 'green');
insert into seat (id, student) values ('5', 'jeames');
insert into seat (id, student) values ('3', 'emerson');

drop table if exists users;
drop table if exists movies;
drop table if exists movierating;

create table if not exists users (user_id int, name varchar(30));
create table if not exists movies (movie_id int, title varchar(30));
create table if not exists movierating (movie_id int, user_id int, rating int, created_at date);

truncate table movies;

insert into movies (movie_id, title) values ('3', 'joker');
insert into movies (movie_id, title) values ('1', 'avengers');
insert into movies (movie_id, title) values ('2', 'frozen 2');

truncate table users;

insert into users (user_id, name) values ('3', 'maria');
insert into users (user_id, name) values ('4', 'james');
insert into users (user_id, name) values ('1', 'daniel');
insert into users (user_id, name) values ('2', 'monica');

truncate table movierating;

insert into movierating (movie_id, user_id, rating, created_at) values ('1', '1', '3', '2020-01-12');
insert into movierating (movie_id, user_id, rating, created_at) values ('1', '2', '4', '2020-02-11');
insert into movierating (movie_id, user_id, rating, created_at) values ('1', '3', '2', '2020-02-12');
insert into movierating (movie_id, user_id, rating, created_at) values ('1', '4', '1', '2020-01-01');
insert into movierating (movie_id, user_id, rating, created_at) values ('2', '1', '5', '2020-02-17');
insert into movierating (movie_id, user_id, rating, created_at) values ('2', '2', '2', '2020-02-01');
insert into movierating (movie_id, user_id, rating, created_at) values ('2', '3', '2', '2020-03-01');
insert into movierating (movie_id, user_id, rating, created_at) values ('3', '1', '3', '2020-02-22');
insert into movierating (movie_id, user_id, rating, created_at) values ('3', '2', '4', '2020-02-25');

create table if not exists customer (customer_id int, name varchar(20), visited_on date, amount int);

drop table if exists customer;

truncate table customer;

insert into customer (customer_id, name, visited_on, amount) values ('1', 'jhon', '2019-01-01', '100');
insert into customer (customer_id, name, visited_on, amount) values ('3', 'jade', '2019-01-03', '120');
insert into customer (customer_id, name, visited_on, amount) values ('7', 'anna', '2019-01-07', '150');
insert into customer (customer_id, name, visited_on, amount) values ('8', 'maria', '2019-01-08', '80');
insert into customer (customer_id, name, visited_on, amount) values ('9', 'jaze', '2019-01-09', '110');
insert into customer (customer_id, name, visited_on, amount) values ('1', 'jhon', '2019-01-10', '130');
insert into customer (customer_id, name, visited_on, amount) values ('3', 'jade', '2019-01-10', '150');
insert into customer (customer_id, name, visited_on, amount) values ('6', 'elvis', '2019-01-06', '140');
insert into customer (customer_id, name, visited_on, amount) values ('2', 'daniel', '2019-01-02', '110');
insert into customer (customer_id, name, visited_on, amount) values ('4', 'khaled', '2019-01-04', '130');
insert into customer (customer_id, name, visited_on, amount) values ('5', 'winston', '2019-01-05', '110');

create table if not exists requestaccepted (requester_id int not null, accepter_id int null, accept_date date null);

truncate table requestaccepted;

insert into requestaccepted (requester_id, accepter_id, accept_date) values ('1', '2', '2016/06/03');
insert into requestaccepted (requester_id, accepter_id, accept_date) values ('1', '3', '2016/06/08');
insert into requestaccepted (requester_id, accepter_id, accept_date) values ('2', '3', '2016/06/08');
insert into requestaccepted (requester_id, accepter_id, accept_date) values ('3', '4', '2016/06/09');

create table if not exists insurance (pid int, tiv_2015 float, tiv_2016 float, lat float, lon float);

truncate table insurance;

insert into insurance (pid, tiv_2015, tiv_2016, lat, lon) values ('1', '10', '5', '10', '10');
insert into insurance (pid, tiv_2015, tiv_2016, lat, lon) values ('2', '20', '20', '20', '20');
insert into insurance (pid, tiv_2015, tiv_2016, lat, lon) values ('3', '10', '30', '20', '20');
insert into insurance (pid, tiv_2015, tiv_2016, lat, lon) values ('4', '10', '40', '40', '40');

drop table if exists employee;

create table if not exists employee (id int, name varchar(255), salary int, departmentid int);

truncate table employee;

insert into employee (id, name, salary, departmentid) values ('1', 'joe', '85000', '1');
insert into employee (id, name, salary, departmentid) values ('3', 'sam', '60000', '2');
insert into employee (id, name, salary, departmentid) values ('4', 'max', '90000', '1');
insert into employee (id, name, salary, departmentid) values ('7', 'will', '70000', '1');
insert into employee (id, name, salary, departmentid) values ('2', 'henry', '80000', '2');
insert into employee (id, name, salary, departmentid) values ('5', 'janet', '69000', '1');
insert into employee (id, name, salary, departmentid) values ('6', 'randy', '85000', '1');

drop table if exists department;

create table if not exists department (id int, name varchar(255));

truncate table department;

insert into department (id, name) values ('1', 'it');
insert into department (id, name) values ('2', 'sales');

create table if not exists users (user_id int, name varchar(40));

truncate table users;

insert into users (user_id, name) values ('2', 'bob');
insert into users (user_id, name) values ('1', 'alice');
