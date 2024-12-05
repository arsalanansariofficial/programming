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