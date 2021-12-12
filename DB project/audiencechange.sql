SET SQL_SAFE_UPDATES = 0;
alter table audiences drop test_result;
alter table audiences add test_result varchar(45);
update audiences set test_result = (select result from zovid12test where zovid12test.id_Number = audiences.id_Number);
select * from audiences