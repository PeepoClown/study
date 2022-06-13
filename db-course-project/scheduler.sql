CREATE DATABASE scheduler;

-- campus table
CREATE TABLE public.campus
(
	id				serial		NOT NULL,
	name			varchar(50)	NOT NULL,
	adress			varchar(50)	NOT NULL,
	phone			varchar(20)	NOT NULL,
	workStart		time		NOT NULL,
	workEnd			time		NOT NULL,
	CONSTRAINT PK_campus PRIMARY KEY (id)
);
-- insert data to campus table
INSERT INTO public.campus (name, adress, phone, workStart, workEnd) VALUES
	('Кампус на проспекте Вернадского 78', 'проспект Вернадского, 78', '+7 (920) 380-22-11', '09:00', '23:00'),
	('Кампус на улице Стромынка', 'улица Стромынка, д. 20', '+7 (930) 970-22-55', '08:00', '22:45'),
	('Кампус на проспекте Вернадского 86', 'проспект Вернадского, 86', '+7 (920) 845-12-24', '09:00', '23:00'),
	('Кампус на улице Соколиная гора', '5-я ул. Соколиной горы, дом 22', '+7 (912) 345-90-80', '09:00', '22:30'),
	('Кампус на улице Малая Пироговская', 'улица Малая Пироговская, д. 1, стр. 5', '+7 (955) 555-92-33', '09:00', '21:00');

-- classroom table
CREATE TABLE public.classroom
(
	id			serial		NOT NULL,
	name		varchar(50)	NOT NULL,
	campus_id	integer		NOT NULL,
	CONSTRAINT PK_classroom PRIMARY KEY (id),
	CONSTRAINT FK_campusToClassroom FOREIGN KEY (campus_id) REFERENCES public.campus (id)
);
-- insert data to classroom table
INSERT INTO public.classroom (name, campus_id) VALUES
	('A-1', 1), ('A-2', 1), ('A-3', 1), ('A-4', 1), ('A-5', 1),
	('A-6', 1), ('A-7', 1), ('A-8', 1), ('Б-132', 1), ('Б-240', 1),
	('В-102', 1), ('В-222', 1), ('Г-188', 1), ('Д-101', 1), ('Е-250', 1),
	('128', 2), ('216', 2), ('249', 2), ('309', 2), ('330', 2),
	('426', 2), ('451', 2), ('К-1', 3), ('К-2', 3), ('У-112', 3),
	('У-200', 3), ('Т-31', 4), ('Т-23', 4), ('22', 5), ('18', 5);

-- subject table
CREATE TABLE public.subject
(
	id		serial			NOT NULL,
	name	varchar(100)	NOT NULL,
	CONSTRAINT PK_subject PRIMARY KEY (id)
);
-- insert data to subject table
INSERT INTO public.subject (name) VALUES
	('Математический анализ'), ('Линейная алгебра'), ('Аналитическая геометрия'),
	('Языки программирования'), ('Компьютерные сети'), ('Базы данных'),
	('Философия'), ('История'), ('Операционные системы');

-- classTime table
CREATE TABLE public.classTime
(
	id			serial	NOT NULL,
	startTime	time	NOT NULL,
	endTime		time	NOT NULL,
	CONSTRAINT PK_class PRIMARY KEY (id)
);
-- insert data to classTime table
INSERT INTO public.classTime (startTime, endTime) VALUES
	('09:00', '10:30'), ('10:40', '12:10'), ('12:40', '14:10'),
	('14:20', '15:50'), ('16:20', '17:50'), ('18:00', '19:30');

-- faculty table
CREATE TABLE public.faculty
(
	id			serial		NOT NULL,
	name		varchar(50)	NOT NULL,
	phone		varchar(20)	NOT NULL,
	email		varchar(50)	NOT NULL,
	chief_id	integer		NOT NULL,
	campus_id	integer		NOT NULL,
	CONSTRAINT PK_faculty PRIMARY KEY (id),
	CONSTRAINT FK_campusToFaculty FOREIGN KEY (campus_id) REFERENCES public.campus (id)
);
-- insert data to faculty table - later

-- cathedra table
CREATE TABLE public.cathedra
(
	id			serial		NOT NULL,
	name		varchar(50)	NOT NULL,
	phone		varchar(20)	NOT NULL,
	email		varchar(50)	NOT NULL,
	faculty_id	integer		NOT NULL,
	campus_id	integer		NOT NULL,
	chief_id	integer		NOT NULL,
	CONSTRAINT PK_cathedra PRIMARY KEY (id),
	CONSTRAINT FK_facultyToCathedra FOREIGN KEY (faculty_id) REFERENCES public.faculty (id),
	CONSTRAINT FK_campusToCathedra FOREIGN KEY (campus_id) REFERENCES public.campus (id)
);
-- insert data to cathedra table - later

-- teacherProfile table
CREATE TABLE public.teacherProfile
(
	id			serial		NOT NULL,
	rank		varchar(50)	NULL,
	grade		varchar(50)	NULL,
	position	varchar(50)	NOT NULL,
	education	varchar(50)	NOT NULL,
	CONSTRAINT PK_teacherprofile PRIMARY KEY (id)
);
-- insert data to teacherProfile table
INSERT INTO public.teacherProfile (rank, grade, position, education) VALUES
	('Кандидат наук', 'Доцент', 'Преподаватель', 'Высшее физ-мат'),
	('Кандидат наук', 'Старший преподаватель', 'Преподаватель', 'Высшее физ-мат'),
	('Кандидат наук', 'Доцент', 'Преподаватель', 'Высшее филологическое'),
	('Доктор наук', 'Профессор', 'Зав. кафедрой', 'Высшее филологическое'),
	('Доктор наук', 'Профессор', 'Зав. кафедрой', 'Высшее физ-мат'),
	('Доктор наук', 'Профессор', 'Преподаватель', 'Высшее физ-мат'),
	(NULL, NULL, 'Преподаватель', 'Высшее физ-мат'),
	('Кандидат наук', 'Доцент', 'Зав. кафедрой', 'Высшее физ-мат');

-- teacher table
CREATE TABLE public.teacher
(
	id					serial		NOT NULL,
	name				varchar(50)	NOT NULL,
	age					integer		NOT NULL,
	phone				varchar(20)	NOT NULL,
	email				varchar(50)	NOT NULL,
	cathedra_id			integer		NOT NULL,
	teacherProfile_id	integer		NOT NULL,
	CONSTRAINT PK_teacher PRIMARY KEY (id),
	CONSTRAINT FK_teacherProfileToTeacher FOREIGN KEY (teacherProfile_id) REFERENCES public.teacherProfile (id)
);
-- insert data to teacher table
INSERT INTO public.teacher (name, age, phone, email, cathedra_id, teacherProfile_id) VALUES
	('Волков Георгий Ильич', 51, '+7 (911) 123-34-45', 'volkov@univer.ru', 1, 6),
	('Баранова Анна Егоровна', 65, '+7 (911) 567-78-89', 'baranova@univer.ru', 1, 5),
	('Кондратьева Злата Глебовна', 26, '+7 (911) 912-23-34', 'kondrateva@univer.ru', 1, 7),
	('Ефремов Марк Даниилович', 28, '+7 (911) 456-67-78', 'efremov@univer.ru', 1, 2),
	('Миронов Владимир Фёдорович', 48, '+7 (912) 123-34-45', 'mironov@univer.ru', 2, 8),
	('Яковлев Герман Иванович', 51, '+7 (913) 123-34-45', 'yakovlev@univer.ru', 3, 8),
	('Савельева Мила Максимовна', 32, '+7 (913) 567-78-89', 'saveleva@univer.ru', 3, 1),
	('Леонова Алиса Николаевна', 45, '+7 (914) 123-34-45', 'leonova@univer.ru', 4, 4),
	('Аксенов Платон Тимофеевич', 31, '+7 (914) 567-78-89', 'aksenov@univer.ru', 4, 3),
	('Борисов Александр Владимирович', 36, '+7 (915) 123-34-45', 'borisov@univer.ru', 5, 5);

-- set field of table faculty - chief_id as FK
ALTER TABLE public.faculty ADD CONSTRAINT FK_teacherToFaculty FOREIGN KEY (chief_id) REFERENCES public.teacher (id);
-- insert data to faculty table
INSERT INTO public.faculty (name, phone, email, chief_id, campus_id) VALUES
	('Технический', '+7 (922) 390-15-69', 'fizmat@univer.ru', 2, 1),
	('Гуманитарный', '+7 (922) 401-26-70', 'gum@univer.ru', 8, 3);

-- set field of table cathedra - chief_id as FK
ALTER TABLE public.cathedra ADD CONSTRAINT FK_teacherToCathedra FOREIGN KEY (chief_id) REFERENCES public.teacher (id);
-- insert data to cathedra table
INSERT INTO public.cathedra (name, phone, email, faculty_id, chief_id, campus_id) VALUES
	('Кафедра Высшей Математики', '+7 (933) 222-33-44', 'math@univer.ru', 1, 2, 1),
	('Кафедра Физики', '+7 (933) 111-22-33', 'fizika@univer.ru', 1, 5, 2),
	('Кафедра Информационных технологий', '+7 (933) 333-44-55', 'it@univer.ru', 1, 6, 1),
	('Кафедра Гуманитарных наук', '+7 (933) 555-66-77', 'guman@univer.ru', 2, 8, 3),
	('Кафедра Информационной безопасности', '+7 (933) 444-55-66', 'infobez@univer.ru', 1, 10, 4);

-- set field of table teacher - cathedra_id as FK
ALTER TABLE public.teacher ADD CONSTRAINT FK_cathedraToTeacher FOREIGN KEY (cathedra_id) REFERENCES public.cathedra (id);

-- teacher specialty
CREATE TABLE public.specialty
(
	id		serial		NOT NULL,
	name	varchar(50)	NOT NULL,
	cipher	varchar(10)	NOT NULL,
	CONSTRAINT PK_specialty PRIMARY KEY (id)
);
-- insert data to specialty table
INSERT INTO public.specialty (name, cipher) VALUES
	('Прикладная математика', '1'), ('Математика и механика', '5'),
	('Прикладная физика', '2'), ('Астрономия', '3'),
	('Прикладная информатика', '4'), ('Программная инженерия', '6'),
	('Филология', '7'), ('Информационная безопасность', '8');

-- group table
CREATE TABLE public.group
(
	id				serial		NOT NULL,
	cipher			varchar(50)	NOT NULL,
	course			integer		NOT NULL,
	studentsCount	integer		NOT NULL,
	cathedra_id		integer		NOT NULL,
	specialty_id	integer		NOT NULL,
	CONSTRAINT PK_group PRIMARY KEY (id),
	CONSTRAINT FK_groupToCathedra FOREIGN KEY (cathedra_id) REFERENCES public.cathedra (id),
	CONSTRAINT FK_groupToSpecialty FOREIGN KEY (specialty_id) REFERENCES public.specialty (id)
);
-- insert data to group table
INSERT INTO public.group (cipher, course, studentsCount, cathedra_id, specialty_id) VALUES
	('БСБО-01', 3, 30, 3, 5), ('БСБО-02', 1, 32, 3, 5),
	('ККК-01', 4, 21, 2, 4), ('ФИБО-01', 1, 35, 2, 3),
	('МЕХА-01', 1, 31, 1, 2), ('МАТАН-01', 1, 32, 1, 1),
	('ИТТО-01', 1, 30, 3, 6), ('ИТТО-01', 3, 25, 3, 6),
	('ФИЛО-01', 2, 33, 4, 7), ('ИНФБ-01', 4, 23, 5, 8),
	('МАТАН-01', 2, 29, 1, 1), ('КЕК-00', 5, 19, 3, 5);

-- table schedule
CREATE TABLE public.schedule
(
	id				serial		NOT NULL,
	subject_id		integer		NOT NULL,
	group_id		integer		NOT NULL,
	teacher_id		integer		NOT NULL,
	classType		varchar(20)	NOT NULL,
	classroom_id	integer		NOT NULL,
	classTime_id	integer		NOT NULL,
	weekDay			varchar(20)	NOT NULL,
	CONSTRAINT PK_schedule PRIMARY KEY (id),
	CONSTRAINT FK_scheduleToSubject FOREIGN KEY (subject_id) REFERENCES public.subject (id),
	CONSTRAINT FK_scheduleToGroup FOREIGN KEY (group_id) REFERENCES public.group (id),
	CONSTRAINT FK_scheduleToTeacher FOREIGN KEY (teacher_id) REFERENCES public.teacher (id),
	CONSTRAINT FK_scheduleToClassroom FOREIGN KEY (classroom_id) REFERENCES public.classroom (id),
	CONSTRAINT FK_scheduleToClassTime FOREIGN KEY (classTime_id) REFERENCES public.classTime (id)
);
-- insert data to schedule table
INSERT INTO public.schedule (subject_id, group_id, teacher_id, classType, classroom_id, classTime_id, weekDay) VALUES
    (5, 1, 9, 'Лекция', 12, 1, 'Понедельник'), (7, 3, 7, 'Лекция', 28, 1, 'Понедельник'), (1, 1, 1, 'Практика', 22, 1, 'Понедельник'),
    (5, 2, 9, 'Лекция', 19, 2, 'Понедельник'), (5, 3, 5, 'Практика', 5, 2, 'Понедельник'), (2, 8, 1, 'Лекция', 6, 3, 'Понедельник'),
    (8, 8, 8, 'Лекция', 25, 3, 'Понедельник'), (6, 1, 5, 'Лекция', 4, 3, 'Понедельник'), (5, 4, 9, 'Лекция', 2, 4, 'Понедельник'),
    (2, 7, 2, 'Практика', 10, 5, 'Понедельник'), (1, 2, 3, 'Практика', 14, 5, 'Понедельник'), (5, 5, 5, 'Практика', 15, 5, 'Понедельник'),
    (1, 3, 2, 'Лекция', 1, 6, 'Понедельник'), (1, 4, 3, 'Лекция', 9, 6, 'Понедельник'), (8, 1, 7, 'Лекция', 18, 1, 'Вторник'),
    (8, 8, 8, 'Практика', 24, 1, 'Вторник'), (6, 2, 5, 'Лекция', 26, 2, 'Вторник'), (5, 6, 5, 'Лекция', 20, 2, 'Вторник'),
    (5, 7, 9, 'Лекция', 30, 2, 'Вторник'), (3, 1, 1, 'Практика', 23, 3, 'Вторник'), (3, 2, 2, 'Лекция', 17, 3, 'Вторник'),
    (6, 7, 6, 'Лекция', 13, 4, 'Вторник'), (4, 1, 5, 'Лекция', 11, 4, 'Вторник'), (7, 8, 8, 'Практика', 21, 4, 'Вторник'),
    (2, 6, 3, 'Лекция', 16, 5, 'Вторник'), (7, 7, 8, 'Лекция', 29, 5, 'Вторник'), (1, 5, 4, 'Практика', 8, 5, 'Вторник'),
    (6, 8, 5, 'Лекция', 7, 1, 'Среда'), (4, 2, 6, 'Лабораторная работа', 27, 1, 'Среда'), (8, 2, 7, 'Практика', 3, 1, 'Среда'),
    (3, 3, 3, 'Лекция', 11, 2, 'Среда'), (1, 6, 1, 'Лекция', 19, 2, 'Среда'), (6, 1, 5, 'Практика', 6, 2, 'Среда'),
    (3, 4, 4, 'Лекция', 3, 3, 'Среда'), (5, 1, 9, 'Лекция', 17, 3, 'Среда'), (3, 7, 1, 'Практика', 4, 3, 'Среда'),
    (5, 8, 5, 'Лекция', 28, 4, 'Среда'), (5, 10, 6, 'Лекция', 25, 5, 'Среда'), (1, 7, 2, 'Практика', 1, 5, 'Среда'),
    (1, 8, 3, 'Лекция', 20, 5, 'Среда'), (6, 2, 6, 'Лекция', 15, 5, 'Среда'), (1, 1, 4, 'Лекция', 14, 1, 'Четверг'),
    (6, 7, 5, 'Практика', 27, 1, 'Четверг'), (7, 8, 8, 'Практика', 8, 2, 'Четверг'), (1, 1, 1, 'Лекция', 29, 2, 'Четверг'),
    (6, 8, 6, 'Практика', 5, 3, 'Четверг'), (6, 1, 5, 'Практика', 30, 3, 'Четверг'), (6, 2, 9, 'Лекция', 24, 3, 'Четверг'),
    (2, 1, 4, 'Практика', 9, 3, 'Четверг'), (2, 2, 1, 'Практика', 16, 4, 'Четверг'), (1, 10, 1, 'Лекция', 7, 4, 'Четверг'),
    (5, 11, 9, 'Практика', 10, 4, 'Четверг'), (8, 8, 7, 'Практика', 26, 4, 'Четверг'), (5, 12, 5, 'Лекция', 13, 4, 'Четверг'),
    (4, 2, 5, 'Лабораторная работа', 12, 5, 'Четверг'), (2, 1, 2, 'Лекция', 7, 1, 'Пятница'), (4, 2, 6, 'Лекция', 22, 1, 'Пятница'),
    (5, 1, 6, 'Лекция', 21, 2, 'Пятница'), (8, 1, 8, 'Лекция', 23, 2, 'Пятница'), (7, 2, 7, 'Лекция', 2, 2, 'Пятница'),
    (4, 1, 5, 'Практика', 12, 2, 'Пятница'), (2, 2, 1, 'Практика', 22, 3, 'Пятница'), (7, 8, 7, 'Лекция', 18, 3, 'Пятница'),
    (2, 3, 3, 'Лекция', 20, 3, 'Пятница'), (5, 4, 9, 'Лекция', 16, 3, 'Пятница'), (4, 7, 5, 'Практика', 11, 3, 'Пятница'),
    (5, 2, 5, 'Лекция', 17, 3, 'Пятница'), (1, 11, 2, 'Лекция', 28, 4, 'Пятница'), (1, 2, 4, 'Практика', 6, 4, 'Пятница'),
    (5, 3, 9, 'Лекция', 12, 4, 'Пятница'), (1, 3, 3, 'Лекция', 2, 5, 'Пятница'), (6, 8, 5, 'Лекция', 26, 1, 'Суббота'),
    (6, 7, 6, 'Лекция', 14, 1, 'Суббота'), (7, 1, 8, 'Лекция', 19, 1, 'Суббота'), (4, 8, 6, 'Лекция', 13, 1, 'Суббота'),
    (7, 8, 7, 'Лекция', 9, 2, 'Суббота'), (4, 10, 6, 'Практика', 29, 2, 'Суббота'), (2, 4, 4, 'Лекция', 25, 2, 'Суббота'),
    (6, 1, 6, 'Практика', 3, 2, 'Суббота'), (6, 2, 5, 'Практика', 24, 3, 'Суббота'), (4, 1, 6, 'Лабораторная работа', 5, 3, 'Суббота'),
    (8, 8, 8, 'Лекция', 8, 3, 'Суббота'), (1, 12, 1, 'Практика', 21, 4, 'Суббота'), (2, 5, 1, 'Лекция', 18, 4, 'Суббота'),
    (9, 1, 4, 'Лекция', 30, 4, 'Суббота'), (9, 7, 5, 'Практика', 22, 4, 'Суббота'), (9, 5, 6, 'Лекция', 15, 5, 'Суббота'),
    (9, 2, 4, 'Лекция', 27, 5, 'Суббота'), (9, 8, 5, 'Лекция', 7, 6, 'Суббота'), (9, 6, 4, 'Практика', 10, 6, 'Суббота');

-- task 2a
-- function for multytable query with param and case operator
CREATE FUNCTION selectGroupsByCourse(_course integer) RETURNS TABLE (GroupCipher varchar(50), Cathedra varchar(50), Capacity text)
LANGUAGE plpgsql
AS $$
BEGIN
    RETURN QUERY
    SELECT public.group.cipher, public.cathedra.name,
    CASE
        WHEN public.group.studentsCount < 20 THEN 'Недобор'
        WHEN public.group.studentsCount <= 32 THEN 'Норма'
        WHEN public.group.studentsCount > 32 THEN 'Перебор'
    END
    FROM public.group
    LEFT JOIN public.cathedra ON public.cathedra.id = public.group.cathedra_id
    WHERE public.group.course = _course;
END;
$$;

-- task 2b
-- create multytable view
CREATE VIEW chiefByGroup AS
SELECT public.group.cipher, public.teacher.name
FROM public.group, public.teacher
LEFT JOIN public.cathedra ON public.cathedra.chief_id = public.teacher.id
WHERE public.group.cathedra_id = public.cathedra.id;
-- function for select view fields in some order
CREATE FUNCTION getChiefByGroup(_field varchar(50)) RETURNS TABLE (GroupCipher varchar(50), ChiefName varchar(50))
LANGUAGE plpgsql
AS $$
BEGIN
    RETURN QUERY
    SELECT * FROM chiefByGroup
    ORDER BY CASE
        WHEN _field = 'g' THEN chiefByGroup.cipher
        WHEN _field = 'c' THEN chiefByGroup.name
        ELSE chiefByGroup.cipher
    END;
END;
$$;

-- task 2c
-- select all teachers which work chief of cathedra and faculty
CREATE FUNCTION getChiefOfCheifs() RETURNS TABLE (Name varchar(50), Age integer,
                                Phone varchar(50), Email varchar(50), Cathedra varchar(50), Faculty varchar(50))
LANGUAGE plpgsql
AS $$
BEGIN
    RETURN QUERY
    SELECT
        teacher.name, teacher.age, teacher.phone, teacher.email,
        (SELECT public.cathedra.name FROM public.cathedra WHERE public.cathedra.chief_id = teacher.id),
        (SELECT public.faculty.name FROM public.faculty WHERE public.faculty.id = 2)
    FROM
        (SELECT * FROM public.teacher) AS teacher
        LEFT JOIN LATERAL (SELECT * FROM public.cathedra WHERE teacher.id = cathedra.chief_id) AS cathedra
        ON teacher.id = cathedra.chief_id
    WHERE
        teacher.id IN (SELECT faculty.chief_id
                       FROM public.faculty AS faculty
                       LEFT JOIN public.teacher on faculty.chief_id = public.teacher.id
                       WHERE public.teacher.name = teacher.name)
        AND
        teacher.age IN (SELECT public.teacher.age
                        FROM public.teacher
                        GROUP BY public.teacher.age
                        HAVING public.teacher.age < 65);
END;
$$;

-- task 2d
-- function for multytable query with grouping and count func call and having operator
CREATE FUNCTION getClassesByTeacher(_pairs integer) RETURNS TABLE (TeacherName varchar(50), WeekDay varchar(50), Pairs bigint)
LANGUAGE plpgsql
AS $$
BEGIN
    RETURN QUERY
    SELECT public.teacher.name, public.schedule.weekDay, COUNT(public.schedule.id)
    FROM public.teacher
    LEFT JOIN public.schedule ON public.teacher.id = public.schedule.teacher_id
    GROUP BY public.teacher.name, public.schedule.weekDay
    HAVING COUNT(public.schedule.id) = _pairs
    ORDER BY public.teacher.name;
END;
$$;

-- task 2e
-- function for query that contains any predicate
CREATE FUNCTION selectGroupsByWeekDay(_weekDay varchar(50)) RETURNS TABLE (GroupCipher varchar(50))
LANGUAGE plpgsql
AS $$
BEGIN
    RETURN QUERY
    SELECT public.group.cipher
    FROM public.group
    WHERE public.group.id = ANY(SELECT public.schedule.group_id FROM public.schedule WHERE public.schedule.weekDay = _weekDay);
END;
$$;

-- task 3
CREATE INDEX campus_idIndex ON public.campus (name);
CREATE INDEX classroom_idIndex ON public.classroom (name);
CREATE INDEX faculty_idIndex ON public.faculty (phone);
CREATE INDEX cathedra_idIndex ON public.cathedra (phone);
CREATE INDEX teacher_idIndex ON public.teacher (name);
CREATE INDEX group_idIndex ON public.group (cipher);
CREATE INDEX schedule_idIndex ON public.schedule (weekDay);

-- task 4
-- create table teacherprofileLogs for trigger test
CREATE TABLE public.teacherprofileLogs
(
    id				serial		    NOT NULL,
	msg	    		varchar(255)	NOT NULL,
	logTime         time            NOT NULL,
	CONSTRAINT PK_teacherprofileLogs PRIMARY KEY (id)
);
-- create trigger function, that called on insert, update and delete records of teacherProfile table
CREATE FUNCTION tr_createLog() RETURNS TRIGGER
LANGUAGE plpgsql
AS $$
    DECLARE
        valueStr    varchar(100);
        msgStr      varchar(100);
        delim       varchar(5);
        resultStr   varchar(255);
    BEGIN
        delim = ' ';
        IF TG_OP = 'INSERT' THEN
            valueStr = NEW.rank || delim || NEW.grade || delim || NEW.position || delim || NEW.education;
            msgStr = 'Add new profile: ';
            resultStr = msgStr || valueStr;
            INSERT INTO public.teacherprofileLogs(msg, logTime) VALUES
                (resultStr, NOW());
            RETURN NEW;
        ELSIF TG_OP = 'UPDATE' THEN
            valueStr = NEW.rank || delim || NEW.grade || delim || NEW.position || delim || NEW.education;
            msgStr = 'Update profile: ' || OLD.rank || delim || OLD.grade || delim || OLD.position || delim || OLD.education || ' to: ';
            resultStr = msgStr || valueStr;
            INSERT INTO public.teacherprofileLogs(msg, logTime) VALUES
                (resultStr, NOW());
            RETURN NEW;
        ELSIF TG_OP = 'DELETE' THEN
            valueStr = OLD.rank || delim || OLD.grade || delim || OLD.position || delim || OLD.education;
            msgStr = 'Delete profile: ';
            resultStr = msgStr || valueStr;
            INSERT INTO public.teacherprofileLogs(msg, logTime) VALUES
                (resultStr, NOW());
            RETURN NEW;
        END IF;
    END;
$$;
-- create trigger for table teaherProfile that called tr_createLog function
CREATE TRIGGER tr_teacherprofile
AFTER INSERT OR UPDATE OR DELETE ON public.teacherProfile
FOR EACH ROW EXECUTE PROCEDURE tr_createLog();

-- task 5
-- procedure for table campus : insert, update, delete
CREATE PROCEDURE campusAdd(_name varchar(50), _adress varchar(50), _phone varchar(50), _workStart time, _workEnd time)
LANGUAGE SQL
AS $$
    INSERT INTO public.campus (name, adress, phone, workStart, workEnd) VALUES
        (_name, _adress, _phone, _workStart, _workEnd);
$$;
CREATE PROCEDURE campusChange(_id integer, _name varchar(50), _adress varchar(50), _phone varchar(50), _workStart time, _workEnd time)
LANGUAGE SQL
AS $$
    UPDATE public.campus
    SET name = _name,
    adress = _adress,
    phone = _phone,
    workStart = _workStart,
    workEnd = _workEnd
    WHERE id = _id;
$$;
CREATE PROCEDURE campusDelete(_id integer)
LANGUAGE SQL
AS $$
    DELETE FROM public.campus
    WHERE id = _id;
$$;

-- procedure for table classroom : insert, update, delete
CREATE PROCEDURE classroomAdd(_name varchar(50), _campus_id integer)
LANGUAGE SQL
AS $$
    INSERT INTO public.classroom (name, campus_id) VALUES
        (_name, _campus_id);
$$;
CREATE PROCEDURE classroomChange(_id integer, _name varchar(50), _campus_id integer)
LANGUAGE SQL
AS $$
    UPDATE public.classroom
    SET name = _name,
    campus_id = _campus_id
    WHERE id = _id;
$$;
CREATE PROCEDURE classroomDelete(_id integer)
LANGUAGE SQL
AS $$
    DELETE FROM public.classroom
    WHERE id = _id;
$$;

-- procedure for table subject : insert, update, delete
CREATE PROCEDURE subjectAdd(_name varchar(50))
LANGUAGE SQL
AS $$
    INSERT INTO public.subject (name) VALUES
        (_name);
$$;
CREATE PROCEDURE subjectChange(_id integer, _name varchar(50))
LANGUAGE SQL
AS $$
    UPDATE public.subject
    SET name = _name
    WHERE id = _id;
$$;
CREATE PROCEDURE subjectDelete(_id integer)
LANGUAGE SQL
AS $$
    DELETE FROM public.subject
    WHERE id = _id;
$$;

-- procedure for table calssTime : insert, update, delete
CREATE PROCEDURE classtimeAdd(_startTime time, _endTime time)
LANGUAGE SQL
AS $$
    INSERT INTO public.classTime (startTime, endTime) VALUES
        (_startTime, _endTime);
$$;
CREATE PROCEDURE classtimeChange(_id integer, _startTime time, _endTime time)
LANGUAGE SQL
AS $$
    UPDATE public.classTime
    SET startTime = _startTime,
        endTime = _endTime
    WHERE id = _id;
$$;
CREATE PROCEDURE classtimeDelete(_id integer)
LANGUAGE SQL
AS $$
    DELETE FROM public.classTime
    WHERE id = _id;
$$;

-- procedure for table faculty : insert, update, delete
CREATE PROCEDURE facultyAdd(_name varchar(50), _phone varchar(20), _email varchar(50), _chief_id integer, _campus_id integer)
LANGUAGE SQL
AS $$
    INSERT INTO public.faculty (name, phone, email, chief_id, campus_id) VALUES
        (_name, _phone, _email, _chief_id, _campus_id);
$$;
CREATE PROCEDURE facultyChange(_id integer, _name varchar(50), _phone varchar(20), _email varchar(50), _chief_id integer, _campus_id integer)
LANGUAGE SQL
AS $$
    UPDATE public.faculty
    SET name = _name,
        phone = _phone,
        email = _email,
        chief_id = _chief_id,
        campus_id = _campus_id
    WHERE id = _id;
$$;
CREATE PROCEDURE facultyDelete(_id integer)
LANGUAGE SQL
AS $$
    DELETE FROM public.faculty
    WHERE id = _id;
$$;

-- procedure for table cathedra : insert, update, delete
CREATE PROCEDURE cathedraAdd(_name varchar(50), _phone varchar(20), _email varchar(50), _faculty_id integer, _chief_id integer, _campus_id integer)
LANGUAGE SQL
AS $$
    INSERT INTO public.cathedra (name, phone, email, faculty_id, chief_id, campus_id) VALUES
        (_name, _phone, _email, _faculty_id, _chief_id, _campus_id);
$$;
CREATE PROCEDURE cathedraChange(_id integer, _name varchar(50), _phone varchar(20), _email varchar(50), _faculty_id integer, _chief_id integer, _campus_id integer)
LANGUAGE SQL
AS $$
    UPDATE public.cathedra
    SET name = _name,
        phone = _phone,
        email = _email,
        faculty_id = _faculty_id,
        chief_id = _chief_id,
        campus_id = _campus_id
    WHERE id = _id;
$$;
CREATE PROCEDURE cathedraDelete(_id integer)
LANGUAGE SQL
AS $$
    DELETE FROM public.cathedra
    WHERE id = _id;
$$;

-- procedure for table teacherProfile : insert, update, delete
CREATE PROCEDURE teacherprofileAdd(_rank varchar(50), _grade varchar(50), _position varchar(50), _education varchar(50))
LANGUAGE SQL
AS $$
    INSERT INTO public.teacherProfile (rank, grade, position, education) VALUES
        (_rank, _grade, _position, _education);
$$;
CREATE PROCEDURE teacherprofileChange(_id integer, _rank varchar(50), _grade varchar(50), _position varchar(50), _education varchar(50))
LANGUAGE SQL
AS $$
    UPDATE public.teacherProfile
    SET rank = _rank,
        grade = _grade,
        position = _position,
        education = _education
    WHERE id = _id;
$$;
CREATE PROCEDURE teacherprofileDelete(_id integer)
LANGUAGE SQL
AS $$
    DELETE FROM public.teacherProfile
    WHERE id = _id;
$$;

-- procedure for table teacher : insert, update, delete
CREATE PROCEDURE teacherAdd(_name varchar(50), _age integer, _phone varchar(20), _email varchar(50), _cathedra_id integer, _teacherProfile_id integer)
LANGUAGE SQL
AS $$
    INSERT INTO public.teacher (name, age, phone, email, cathedra_id, teacherProfile_id) VALUES
        (_name, _age, _phone, _email, _cathedra_id, _teacherProfile_id);
$$;
CREATE PROCEDURE teacherChange(_id integer, _name varchar(50), _age integer, _phone varchar(20), _email varchar(50), _cathedra_id integer, _teacherProfile_id integer)
LANGUAGE SQL
AS $$
    UPDATE public.teacher
    SET name = _name,
        age = _age,
        phone = _phone,
        email = _email,
        cathedra_id = _cathedra_id,
        teacherProfile_id = _teacherProfile_id
    WHERE id = _id;
$$;
CREATE PROCEDURE teacherDelete(_id integer)
LANGUAGE SQL
AS $$
    DELETE FROM public.teacher
    WHERE id = _id;
$$;

-- procedure for table specialty : insert, update, delete
CREATE PROCEDURE specialtyAdd(_name varchar(50), _cipher varchar(10))
LANGUAGE SQL
AS $$
    INSERT INTO public.specialty (name, cipher) VALUES
        (_name, _cipher);
$$;
CREATE PROCEDURE specialtyChange(_id integer, _name varchar(50), _cipher varchar(10))
LANGUAGE SQL
AS $$
    UPDATE public.specialty
    SET name = _name,
        cipher = _cipher
    WHERE id = _id;
$$;
CREATE PROCEDURE specialtyDelete(_id integer)
LANGUAGE SQL
AS $$
    DELETE FROM public.specialty
    WHERE id = _id;
$$;

-- procedure for table group : insert, update, delete
CREATE PROCEDURE groupAdd(_cipher varchar(50), _course integer, _studentsCount integer, _cathedra_id integer, _specialty_id integer)
LANGUAGE SQL
AS $$
    INSERT INTO public.group (cipher, course, studentsCount, cathedra_id, specialty_id) VALUES
        (_cipher, _course, _studentsCount, _cathedra_id, _specialty_id);
$$;
CREATE PROCEDURE groupChange(_id integer, _cipher varchar(50), _course integer, _studentsCount integer, _cathedra_id integer, _specialty_id integer)
LANGUAGE SQL
AS $$
    UPDATE public.group
    SET cipher = _cipher,
        course = _course,
        studentsCount = _studentsCount,
        cathedra_id = _cathedra_id,
        specialty_id = _specialty_id
    WHERE id = _id;
$$;
CREATE PROCEDURE groupDelete(_id integer)
LANGUAGE SQL
AS $$
    DELETE FROM public.group
    WHERE id = _id;
$$;

-- procedure for table schedule : insert, update, delete
CREATE PROCEDURE scheduleAdd(_subject_id integer, _group_id integer, _teacher_id integer, _classType varchar(20), _classroom_id integer,
                            _classTime_id integer, _weekDay varchar(20))
LANGUAGE SQL
AS $$
    INSERT INTO public.schedule (subject_id, group_id, teacher_id, classType, classroom_id, classTime_id, weekDay) VALUES
        (_subject_id, _group_id, _teacher_id, _classType, _classroom_id, _classTime_id, _weekDay);
$$;
CREATE PROCEDURE scheduleChange(_id integer, _subject_id integer, _group_id integer, _teacher_id integer, _classType varchar(20),
                                _classroom_id integer, _classTime_id integer, _weekDay varchar(20))
LANGUAGE SQL
AS $$
    UPDATE public.schedule
    SET subject_id = _subject_id,
        group_id = _group_id,
        teacher_id = _teacher_id,
        classType = _classType,
        classroom_id = _classroom_id,
        classTime_id = _classTime_id,
        weekDay = _weekDay
    WHERE id = _id;
$$;
CREATE PROCEDURE scheduleDelete(_id integer)
LANGUAGE SQL
AS $$
    DELETE FROM public.schedule
    WHERE id = _id;
$$;

-- task 6
-- create procedure with rollback on invalid transaction(passing cipher that already exist)
CREATE PROCEDURE rollbackIfInvalidAdd(_cipher varchar(50), _course integer, _studentsCount integer, _cathedra_id integer, _specialty_id integer)
LANGUAGE plpgsql
AS $$
DECLARE
    row     record;
    flag    integer;
BEGIN
    flag = 0;
    START TRANSACTION
    FOR row IN SELECT * FROM public.group
    LOOP
        IF row.cipher = _cipher THEN
            flag = 1;
        END IF;
    END LOOP;
    INSERT INTO public.group (cipher, course, studentsCount, cathedra_id, specialty_id) VALUES
        (_cipher, _course, _studentsCount, _cathedra_id, _specialty_id);
    IF flag = 1 THEN
        ROLLBACK;
    END IF;
    COMMIT TRANSACTION;
END;
$$;

DROP PROCEDURE rollbackIfInvalidAdd;

-- task 7
-- in procedure cursor was created
CREATE PROCEDURE rollbackIfInvalidAdd(_cipher varchar(50), _course integer, _studentsCount integer, _cathedra_id integer, _specialty_id integer)
LANGUAGE plpgsql
AS $$
DECLARE
    cur     refcursor;
    row     record;
    flag    integer;
BEGIN
    flag = 0;
    START TRANSACTION
    OPEN cur FOR SELECT * FROM public.group;
    LOOP FETCH cur INTO row;
        IF row.cipher = _cipher THEN
            flag = 1;
        END IF;
        EXIT WHEN NOT FOUND;
    END LOOP;
    CLOSE cur;
    INSERT INTO public.group (cipher, course, studentsCount, cathedra_id, specialty_id) VALUES
        (_cipher, _course, _studentsCount, _cathedra_id, _specialty_id);
    IF flag = 1 THEN
        ROLLBACK;
    END IF;
    COMMIT TRANSACTION;
END;
$$;

-- task 8.1 function that returns the oldest teacher - scalar returns type
CREATE FUNCTION getOldestTeacher() RETURNS varchar(50)
LANGUAGE plpgsql
AS $$
DECLARE
    ret varchar(50);
BEGIN
    ret = (SELECT public.teacher.name
           FROM public.teacher
           WHERE public.teacher.age IN (SELECT MAX(public.teacher.age)
                                        FROM public.teacher));
    RETURN ret;
END;
$$;

-- task 8.2 function for selection of available classrooms - table returns type
CREATE FUNCTION showFreeClassrooms(_pair integer, _weekDay varchar(50)) RETURNS TABLE (Classroom varchar(50))
LANGUAGE plpgsql
AS $$
BEGIN
RETURN QUERY
    SELECT public.classroom.name
    FROM public.classroom
    WHERE public.classroom.name NOT IN (
        SELECT public.classroom.name
        FROM public.classroom, public.schedule
        WHERE public.classroom.id = public.schedule.classroom_id and
              public.schedule.weekDay = _weekDay and
              public.schedule.classTime_id = _pair);
END;
$$;

-- task 9 admin, dmitriy - superusers, usr - sample user
CREATE ROLE admin WITH LOGIN SUPERUSER CREATEDB CREATEROLE PASSWORD '12345';
GRANT ALL PRIVILEGES ON ALL TABLES IN SCHEMA public TO admin;
CREATE USER dmitriy WITH PASSWORD '12345' IN ROLE admin;
ALTER DATABASE scheduler OWNER TO dmitriy;

CREATE ROLE usr WITH LOGIN PASSWORD 'qwerty';
GRANT SELECT ON ALL TABLES IN SCHEMA public TO usr;
