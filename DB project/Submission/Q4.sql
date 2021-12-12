SET SQL_SAFE_UPDATES = 0;
set global sql_mode='STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION';
set session sql_mode='STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION';

alter table audiences drop test_result;
alter table audiences add test_result text;
update audiences set test_result = (select result from zovid12test where  audiences.id_Number = zovid12test.id_Number);
update audiences set test_result = "False" where test_result is null;

alter table audiences drop score;
alter table audiences add score float;
update audiences set score = (select score from census where census.id_Number = audiences.id_Number);

select * from audiences;
select count(*) from audiences;