CREATE TABLE student (name STRING, id INTEGER, age INTEGER, sex STRING );
INSERT 'input' INTO student;
SELECT sex, id, name FROM student AS s WHERE sex != 'M' AND age != 20 AND (name = 'deeksha' OR id >= 1000);
