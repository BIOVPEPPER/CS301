SET SQL_SAFE_UPDATES = 0;
set global sql_mode='STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION';
set session sql_mode='STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION';

create table positive_exam as (select id_Number, vital_cap, metabolism, exam_date from (positive_cases left join positive_physical_exam on positive_cases.case_Number = positive_physical_exam.case_Number));
insert into patients_physical_exam(id_Number, vital_cap, metabolism, exam_date) select id_Number, vital_cap, metabolism, exam_date from positive_exam;
select * from positive_exam;

alter table census drop score;
alter table census add score real;
update census set score = 25*(
	(select vital_cap from (select*from patients_physical_exam where id_Number=census.id_Number order by exam_date desc) as f group by id_Number)/5200
    + (select metabolism from (select * from patients_physical_exam where id_Number = census.id_Number order by exam_date desc) as s group by id_Number)/2800
    +(1- ABS(age-25)/75)
    +(1-ABS(BMI-23)/30)
    );

update census set score =(select * from (select avg(score) from census) ave) where score is null;
select * from census;