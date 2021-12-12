SET SQL_SAFE_UPDATES = 0;

alter table census drop score;
alter table census add score double;

with score as (SELECT 25*(vital_cap/5200 + metabolism/2800 + 1 - ABS(age-25)/75 + 1 - ABS(bmi-23)/30) as score, c.id_Number from patients_physical_exam ppe
inner join (
select MAX(exam_date) as `date`, ppe.id_Number
from patients_physical_exam ppe
group by ppe.id_Number) d on ppe.id_Number=d.id_Number inner join patient_info pi on ppe.id_Number=pi.id_Number inner join census c on ppe.id_Number=c.id_Number)
update census c
inner join score s on c.id_Number=s.id_Number
set c.score = s.score
;

set avgscore = (select avg(score) from census where score is not null);
update census set score = avgscore where score is null;
SELECT * FROM census;
