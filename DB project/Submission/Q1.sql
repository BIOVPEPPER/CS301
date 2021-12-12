SET SQL_SAFE_UPDATES = 0;
alter table census drop age;
ALTER TABLE census ADD age INT;
update census set age = 2021 - substring(cast(id_number as char(20)),6,4);
select * from census;