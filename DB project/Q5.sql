SET SQL_SAFE_UPDATES = 0;
create table f as (select * from city_policy natural left join level_description order by city);
update f set description=(select description from level_description where level_description.level = f.level);
select * from f;