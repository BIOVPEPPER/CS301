SET SQL_SAFE_UPDATES = 0;
#ALTER TABLE census ADD PRIMARY KEY (id_Number);
Alter table patient_info add primary key(id_Number);

alter table census drop BMI; 
ALTER TABLE census ADD BMI DOUBLE;
update census set BMI = null;
update census set BMI = (select weight_kg from patient_info where patient_info.id_Number = census.id_Number)/(POW(((select height_cm from patient_info where patient_info.id_Number = census.id_Number)/100),2));
select * from census;


