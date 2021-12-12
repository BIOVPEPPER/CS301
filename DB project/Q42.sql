SET SQL_SAFE_UPDATES = 0;


alter table audiences add test_result varchar(45);
update audiences set test_result = (select result from zovid12test where zovid12test.id_Number = audiences.id_Number);
alter table audiences add score double;
create table c2 as select census.* from (census
        LEFT JOIN
    audiences ON census.id_Number = audiences.id_Number);
    
update audiences set score = (SELECT 
    distinct score
FROM
	c2);

select * from audiences;
