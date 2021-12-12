create table f1 as (select Name from (select * from patient_info natural right join dbproject.positive_cases)as f);
select Name from f1 where Name like "%B%" or "%b%" ;
select count(Name) from f1 where Name like "%B%" or "%b%" ;