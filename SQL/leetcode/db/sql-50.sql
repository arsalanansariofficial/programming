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