--
-- PostgreSQL database dump
--

-- Dumped from database version 13.1
-- Dumped by pg_dump version 13.1

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

--
-- Name: campusadd(character varying, character varying, character varying, time without time zone, time without time zone); Type: PROCEDURE; Schema: public; Owner: dmitriy
--

CREATE PROCEDURE public.campusadd(_name character varying, _adress character varying, _phone character varying, _workstart time without time zone, _workend time without time zone)
    LANGUAGE sql
    AS $$
    INSERT INTO public.campus (name, adress, phone, workStart, workEnd) VALUES
        (_name, _adress, _phone, _workStart, _workEnd);
$$;


ALTER PROCEDURE public.campusadd(_name character varying, _adress character varying, _phone character varying, _workstart time without time zone, _workend time without time zone) OWNER TO dmitriy;

--
-- Name: campuschange(integer, character varying, character varying, character varying, time without time zone, time without time zone); Type: PROCEDURE; Schema: public; Owner: dmitriy
--

CREATE PROCEDURE public.campuschange(_id integer, _name character varying, _adress character varying, _phone character varying, _workstart time without time zone, _workend time without time zone)
    LANGUAGE sql
    AS $$
    UPDATE public.campus
    SET name = _name,
    adress = _adress,
    phone = _phone,
    workStart = _workStart,
    workEnd = _workEnd
    WHERE id = _id;
$$;


ALTER PROCEDURE public.campuschange(_id integer, _name character varying, _adress character varying, _phone character varying, _workstart time without time zone, _workend time without time zone) OWNER TO dmitriy;

--
-- Name: campusdelete(integer); Type: PROCEDURE; Schema: public; Owner: dmitriy
--

CREATE PROCEDURE public.campusdelete(_id integer)
    LANGUAGE sql
    AS $$
    DELETE FROM public.campus
    WHERE id = _id;
$$;


ALTER PROCEDURE public.campusdelete(_id integer) OWNER TO dmitriy;

--
-- Name: cathedraadd(character varying, character varying, character varying, integer, integer, integer); Type: PROCEDURE; Schema: public; Owner: dmitriy
--

CREATE PROCEDURE public.cathedraadd(_name character varying, _phone character varying, _email character varying, _faculty_id integer, _chief_id integer, _campus_id integer)
    LANGUAGE sql
    AS $$
    INSERT INTO public.cathedra (name, phone, email, faculty_id, chief_id, campus_id) VALUES
        (_name, _phone, _email, _faculty_id, _chief_id, _campus_id);
$$;


ALTER PROCEDURE public.cathedraadd(_name character varying, _phone character varying, _email character varying, _faculty_id integer, _chief_id integer, _campus_id integer) OWNER TO dmitriy;

--
-- Name: cathedrachange(integer, character varying, character varying, character varying, integer, integer, integer); Type: PROCEDURE; Schema: public; Owner: dmitriy
--

CREATE PROCEDURE public.cathedrachange(_id integer, _name character varying, _phone character varying, _email character varying, _faculty_id integer, _chief_id integer, _campus_id integer)
    LANGUAGE sql
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


ALTER PROCEDURE public.cathedrachange(_id integer, _name character varying, _phone character varying, _email character varying, _faculty_id integer, _chief_id integer, _campus_id integer) OWNER TO dmitriy;

--
-- Name: cathedradelete(integer); Type: PROCEDURE; Schema: public; Owner: dmitriy
--

CREATE PROCEDURE public.cathedradelete(_id integer)
    LANGUAGE sql
    AS $$
    DELETE FROM public.cathedra
    WHERE id = _id;
$$;


ALTER PROCEDURE public.cathedradelete(_id integer) OWNER TO dmitriy;

--
-- Name: classroomadd(character varying, integer); Type: PROCEDURE; Schema: public; Owner: dmitriy
--

CREATE PROCEDURE public.classroomadd(_name character varying, _campus_id integer)
    LANGUAGE sql
    AS $$
    INSERT INTO public.classroom (name, campus_id) VALUES
        (_name, _campus_id);
$$;


ALTER PROCEDURE public.classroomadd(_name character varying, _campus_id integer) OWNER TO dmitriy;

--
-- Name: classroomchange(integer, character varying, integer); Type: PROCEDURE; Schema: public; Owner: dmitriy
--

CREATE PROCEDURE public.classroomchange(_id integer, _name character varying, _campus_id integer)
    LANGUAGE sql
    AS $$
    UPDATE public.classroom
    SET name = _name,
    campus_id = _campus_id
    WHERE id = _id;
$$;


ALTER PROCEDURE public.classroomchange(_id integer, _name character varying, _campus_id integer) OWNER TO dmitriy;

--
-- Name: classroomdelete(integer); Type: PROCEDURE; Schema: public; Owner: dmitriy
--

CREATE PROCEDURE public.classroomdelete(_id integer)
    LANGUAGE sql
    AS $$
    DELETE FROM public.classroom
    WHERE id = _id;
$$;


ALTER PROCEDURE public.classroomdelete(_id integer) OWNER TO dmitriy;

--
-- Name: classtimeadd(time without time zone, time without time zone); Type: PROCEDURE; Schema: public; Owner: dmitriy
--

CREATE PROCEDURE public.classtimeadd(_starttime time without time zone, _endtime time without time zone)
    LANGUAGE sql
    AS $$
    INSERT INTO public.classTime (startTime, endTime) VALUES
        (_startTime, _endTime);
$$;


ALTER PROCEDURE public.classtimeadd(_starttime time without time zone, _endtime time without time zone) OWNER TO dmitriy;

--
-- Name: classtimechange(integer, time without time zone, time without time zone); Type: PROCEDURE; Schema: public; Owner: dmitriy
--

CREATE PROCEDURE public.classtimechange(_id integer, _starttime time without time zone, _endtime time without time zone)
    LANGUAGE sql
    AS $$
    UPDATE public.classTime
    SET startTime = _startTime,
        endTime = _endTime
    WHERE id = _id;
$$;


ALTER PROCEDURE public.classtimechange(_id integer, _starttime time without time zone, _endtime time without time zone) OWNER TO dmitriy;

--
-- Name: classtimedelete(integer); Type: PROCEDURE; Schema: public; Owner: dmitriy
--

CREATE PROCEDURE public.classtimedelete(_id integer)
    LANGUAGE sql
    AS $$
    DELETE FROM public.classTime
    WHERE id = _id;
$$;


ALTER PROCEDURE public.classtimedelete(_id integer) OWNER TO dmitriy;

--
-- Name: facultyadd(character varying, character varying, character varying, integer, integer); Type: PROCEDURE; Schema: public; Owner: dmitriy
--

CREATE PROCEDURE public.facultyadd(_name character varying, _phone character varying, _email character varying, _chief_id integer, _campus_id integer)
    LANGUAGE sql
    AS $$
    INSERT INTO public.faculty (name, phone, email, chief_id, campus_id) VALUES
        (_name, _phone, _email, _chief_id, _campus_id);
$$;


ALTER PROCEDURE public.facultyadd(_name character varying, _phone character varying, _email character varying, _chief_id integer, _campus_id integer) OWNER TO dmitriy;

--
-- Name: facultychange(integer, character varying, character varying, character varying, integer, integer); Type: PROCEDURE; Schema: public; Owner: dmitriy
--

CREATE PROCEDURE public.facultychange(_id integer, _name character varying, _phone character varying, _email character varying, _chief_id integer, _campus_id integer)
    LANGUAGE sql
    AS $$
    UPDATE public.faculty
    SET name = _name,
        phone = _phone,
        email = _email,
        chief_id = _chief_id,
        campus_id = _campus_id
    WHERE id = _id;
$$;


ALTER PROCEDURE public.facultychange(_id integer, _name character varying, _phone character varying, _email character varying, _chief_id integer, _campus_id integer) OWNER TO dmitriy;

--
-- Name: facultydelete(integer); Type: PROCEDURE; Schema: public; Owner: dmitriy
--

CREATE PROCEDURE public.facultydelete(_id integer)
    LANGUAGE sql
    AS $$
    DELETE FROM public.faculty
    WHERE id = _id;
$$;


ALTER PROCEDURE public.facultydelete(_id integer) OWNER TO dmitriy;

--
-- Name: getchiefbygroup(character varying); Type: FUNCTION; Schema: public; Owner: dmitriy
--

CREATE FUNCTION public.getchiefbygroup(_field character varying) RETURNS TABLE(groupcipher character varying, chiefname character varying)
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


ALTER FUNCTION public.getchiefbygroup(_field character varying) OWNER TO dmitriy;

--
-- Name: getchiefofcheifs(); Type: FUNCTION; Schema: public; Owner: dmitriy
--

CREATE FUNCTION public.getchiefofcheifs() RETURNS TABLE(name character varying, age integer, phone character varying, email character varying, cathedra character varying, faculty character varying)
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


ALTER FUNCTION public.getchiefofcheifs() OWNER TO dmitriy;

--
-- Name: getclassesbyteacher(integer); Type: FUNCTION; Schema: public; Owner: dmitriy
--

CREATE FUNCTION public.getclassesbyteacher(_pairs integer) RETURNS TABLE(teachername character varying, weekday character varying, pairs bigint)
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


ALTER FUNCTION public.getclassesbyteacher(_pairs integer) OWNER TO dmitriy;

--
-- Name: getoldestteacher(); Type: FUNCTION; Schema: public; Owner: dmitriy
--

CREATE FUNCTION public.getoldestteacher() RETURNS character varying
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


ALTER FUNCTION public.getoldestteacher() OWNER TO dmitriy;

--
-- Name: groupadd(character varying, integer, integer, integer, integer); Type: PROCEDURE; Schema: public; Owner: dmitriy
--

CREATE PROCEDURE public.groupadd(_cipher character varying, _course integer, _studentscount integer, _cathedra_id integer, _specialty_id integer)
    LANGUAGE sql
    AS $$
    INSERT INTO public.group (cipher, course, studentsCount, cathedra_id, specialty_id) VALUES
        (_cipher, _course, _studentsCount, _cathedra_id, _specialty_id);
$$;


ALTER PROCEDURE public.groupadd(_cipher character varying, _course integer, _studentscount integer, _cathedra_id integer, _specialty_id integer) OWNER TO dmitriy;

--
-- Name: groupchange(integer, character varying, integer, integer, integer, integer); Type: PROCEDURE; Schema: public; Owner: dmitriy
--

CREATE PROCEDURE public.groupchange(_id integer, _cipher character varying, _course integer, _studentscount integer, _cathedra_id integer, _specialty_id integer)
    LANGUAGE sql
    AS $$
    UPDATE public.group
    SET cipher = _cipher,
        course = _course,
        studentsCount = _studentsCount,
        cathedra_id = _cathedra_id,
        specialty_id = _specialty_id
    WHERE id = _id;
$$;


ALTER PROCEDURE public.groupchange(_id integer, _cipher character varying, _course integer, _studentscount integer, _cathedra_id integer, _specialty_id integer) OWNER TO dmitriy;

--
-- Name: groupdelete(integer); Type: PROCEDURE; Schema: public; Owner: dmitriy
--

CREATE PROCEDURE public.groupdelete(_id integer)
    LANGUAGE sql
    AS $$
    DELETE FROM public.group
    WHERE id = _id;
$$;


ALTER PROCEDURE public.groupdelete(_id integer) OWNER TO dmitriy;

--
-- Name: rollbackifinvalidadd(character varying, integer, integer, integer, integer); Type: PROCEDURE; Schema: public; Owner: dmitriy
--

CREATE PROCEDURE public.rollbackifinvalidadd(_cipher character varying, _course integer, _studentscount integer, _cathedra_id integer, _specialty_id integer)
    LANGUAGE plpgsql
    AS $$
DECLARE
    cur     refcursor;
    row     record;
    flag    integer;
BEGIN
    flag = 0;
    OPEN cur FOR SELECT * FROM public.group;
    LOOP
        FETCH cur INTO row;
        IF row.cipher = _cipher THEN
            flag = 1;
        END IF;
        EXIT WHEN NOT FOUND;
    END LOOP;
    CLOSE cur;
    IF flag = 0 THEN
        INSERT INTO public.group (cipher, course, studentsCount, cathedra_id, specialty_id) VALUES
            (_cipher, _course, _studentsCount, _cathedra_id, _specialty_id);
    END IF;
END;
$$;


ALTER PROCEDURE public.rollbackifinvalidadd(_cipher character varying, _course integer, _studentscount integer, _cathedra_id integer, _specialty_id integer) OWNER TO dmitriy;

--
-- Name: scheduleadd(integer, integer, integer, character varying, integer, integer, character varying); Type: PROCEDURE; Schema: public; Owner: dmitriy
--

CREATE PROCEDURE public.scheduleadd(_subject_id integer, _group_id integer, _teacher_id integer, _classtype character varying, _classroom_id integer, _classtime_id integer, _weekday character varying)
    LANGUAGE sql
    AS $$
    INSERT INTO public.schedule (subject_id, group_id, teacher_id, classType, classroom_id, classTime_id, weekDay) VALUES
        (_subject_id, _group_id, _teacher_id, _classType, _classroom_id, _classTime_id, _weekDay);
$$;


ALTER PROCEDURE public.scheduleadd(_subject_id integer, _group_id integer, _teacher_id integer, _classtype character varying, _classroom_id integer, _classtime_id integer, _weekday character varying) OWNER TO dmitriy;

--
-- Name: schedulechange(integer, integer, integer, integer, character varying, integer, integer, character varying); Type: PROCEDURE; Schema: public; Owner: dmitriy
--

CREATE PROCEDURE public.schedulechange(_id integer, _subject_id integer, _group_id integer, _teacher_id integer, _classtype character varying, _classroom_id integer, _classtime_id integer, _weekday character varying)
    LANGUAGE sql
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


ALTER PROCEDURE public.schedulechange(_id integer, _subject_id integer, _group_id integer, _teacher_id integer, _classtype character varying, _classroom_id integer, _classtime_id integer, _weekday character varying) OWNER TO dmitriy;

--
-- Name: scheduledelete(integer); Type: PROCEDURE; Schema: public; Owner: dmitriy
--

CREATE PROCEDURE public.scheduledelete(_id integer)
    LANGUAGE sql
    AS $$
    DELETE FROM public.schedule
    WHERE id = _id;
$$;


ALTER PROCEDURE public.scheduledelete(_id integer) OWNER TO dmitriy;

--
-- Name: selectgroupsbycourse(integer); Type: FUNCTION; Schema: public; Owner: dmitriy
--

CREATE FUNCTION public.selectgroupsbycourse(_course integer) RETURNS TABLE(groupcipher character varying, cathedra character varying, capacity text)
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


ALTER FUNCTION public.selectgroupsbycourse(_course integer) OWNER TO dmitriy;

--
-- Name: selectgroupsbyweekday(character varying); Type: FUNCTION; Schema: public; Owner: dmitriy
--

CREATE FUNCTION public.selectgroupsbyweekday(_weekday character varying) RETURNS TABLE(groupcipher character varying)
    LANGUAGE plpgsql
    AS $$
BEGIN
    RETURN QUERY
    SELECT public.group.cipher
    FROM public.group
    WHERE public.group.id = ANY(SELECT public.schedule.group_id FROM public.schedule WHERE public.schedule.weekDay = _weekDay);
END;
$$;


ALTER FUNCTION public.selectgroupsbyweekday(_weekday character varying) OWNER TO dmitriy;

--
-- Name: showfreeclassrooms(integer, character varying); Type: FUNCTION; Schema: public; Owner: dmitriy
--

CREATE FUNCTION public.showfreeclassrooms(_pair integer, _weekday character varying) RETURNS TABLE(classroom character varying)
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


ALTER FUNCTION public.showfreeclassrooms(_pair integer, _weekday character varying) OWNER TO dmitriy;

--
-- Name: specialtyadd(character varying, character varying); Type: PROCEDURE; Schema: public; Owner: dmitriy
--

CREATE PROCEDURE public.specialtyadd(_name character varying, _cipher character varying)
    LANGUAGE sql
    AS $$
    INSERT INTO public.specialty (name, cipher) VALUES
        (_name, _cipher);
$$;


ALTER PROCEDURE public.specialtyadd(_name character varying, _cipher character varying) OWNER TO dmitriy;

--
-- Name: specialtychange(integer, character varying, character varying); Type: PROCEDURE; Schema: public; Owner: dmitriy
--

CREATE PROCEDURE public.specialtychange(_id integer, _name character varying, _cipher character varying)
    LANGUAGE sql
    AS $$
    UPDATE public.specialty
    SET name = _name,
        cipher = _cipher
    WHERE id = _id;
$$;


ALTER PROCEDURE public.specialtychange(_id integer, _name character varying, _cipher character varying) OWNER TO dmitriy;

--
-- Name: specialtydelete(integer); Type: PROCEDURE; Schema: public; Owner: dmitriy
--

CREATE PROCEDURE public.specialtydelete(_id integer)
    LANGUAGE sql
    AS $$
    DELETE FROM public.specialty
    WHERE id = _id;
$$;


ALTER PROCEDURE public.specialtydelete(_id integer) OWNER TO dmitriy;

--
-- Name: subjectadd(character varying); Type: PROCEDURE; Schema: public; Owner: dmitriy
--

CREATE PROCEDURE public.subjectadd(_name character varying)
    LANGUAGE sql
    AS $$
    INSERT INTO public.subject (name) VALUES
        (_name);
$$;


ALTER PROCEDURE public.subjectadd(_name character varying) OWNER TO dmitriy;

--
-- Name: subjectchange(integer, character varying); Type: PROCEDURE; Schema: public; Owner: dmitriy
--

CREATE PROCEDURE public.subjectchange(_id integer, _name character varying)
    LANGUAGE sql
    AS $$
    UPDATE public.subject
    SET name = _name
    WHERE id = _id;
$$;


ALTER PROCEDURE public.subjectchange(_id integer, _name character varying) OWNER TO dmitriy;

--
-- Name: subjectdelete(integer); Type: PROCEDURE; Schema: public; Owner: dmitriy
--

CREATE PROCEDURE public.subjectdelete(_id integer)
    LANGUAGE sql
    AS $$
    DELETE FROM public.subject
    WHERE id = _id;
$$;


ALTER PROCEDURE public.subjectdelete(_id integer) OWNER TO dmitriy;

--
-- Name: teacheradd(character varying, integer, character varying, character varying, integer, integer); Type: PROCEDURE; Schema: public; Owner: dmitriy
--

CREATE PROCEDURE public.teacheradd(_name character varying, _age integer, _phone character varying, _email character varying, _cathedra_id integer, _teacherprofile_id integer)
    LANGUAGE sql
    AS $$
    INSERT INTO public.teacher (name, age, phone, email, cathedra_id, teacherProfile_id) VALUES
        (_name, _age, _phone, _email, _cathedra_id, _teacherProfile_id);
$$;


ALTER PROCEDURE public.teacheradd(_name character varying, _age integer, _phone character varying, _email character varying, _cathedra_id integer, _teacherprofile_id integer) OWNER TO dmitriy;

--
-- Name: teacherchange(integer, character varying, integer, character varying, character varying, integer, integer); Type: PROCEDURE; Schema: public; Owner: dmitriy
--

CREATE PROCEDURE public.teacherchange(_id integer, _name character varying, _age integer, _phone character varying, _email character varying, _cathedra_id integer, _teacherprofile_id integer)
    LANGUAGE sql
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


ALTER PROCEDURE public.teacherchange(_id integer, _name character varying, _age integer, _phone character varying, _email character varying, _cathedra_id integer, _teacherprofile_id integer) OWNER TO dmitriy;

--
-- Name: teacherdelete(integer); Type: PROCEDURE; Schema: public; Owner: dmitriy
--

CREATE PROCEDURE public.teacherdelete(_id integer)
    LANGUAGE sql
    AS $$
    DELETE FROM public.teacher
    WHERE id = _id;
$$;


ALTER PROCEDURE public.teacherdelete(_id integer) OWNER TO dmitriy;

--
-- Name: teacherprofileadd(character varying, character varying, character varying, character varying); Type: PROCEDURE; Schema: public; Owner: dmitriy
--

CREATE PROCEDURE public.teacherprofileadd(_rank character varying, _grade character varying, _position character varying, _education character varying)
    LANGUAGE sql
    AS $$
    INSERT INTO public.teacherProfile (rank, grade, position, education) VALUES
        (_rank, _grade, _position, _education);
$$;


ALTER PROCEDURE public.teacherprofileadd(_rank character varying, _grade character varying, _position character varying, _education character varying) OWNER TO dmitriy;

--
-- Name: teacherprofilechange(integer, character varying, character varying, character varying, character varying); Type: PROCEDURE; Schema: public; Owner: dmitriy
--

CREATE PROCEDURE public.teacherprofilechange(_id integer, _rank character varying, _grade character varying, _position character varying, _education character varying)
    LANGUAGE sql
    AS $$
    UPDATE public.teacherProfile
    SET rank = _rank,
        grade = _grade,
        position = _position,
        education = _education
    WHERE id = _id;
$$;


ALTER PROCEDURE public.teacherprofilechange(_id integer, _rank character varying, _grade character varying, _position character varying, _education character varying) OWNER TO dmitriy;

--
-- Name: teacherprofiledelete(integer); Type: PROCEDURE; Schema: public; Owner: dmitriy
--

CREATE PROCEDURE public.teacherprofiledelete(_id integer)
    LANGUAGE sql
    AS $$
    DELETE FROM public.teacherProfile
    WHERE id = _id;
$$;


ALTER PROCEDURE public.teacherprofiledelete(_id integer) OWNER TO dmitriy;

--
-- Name: tr_createlog(); Type: FUNCTION; Schema: public; Owner: dmitriy
--

CREATE FUNCTION public.tr_createlog() RETURNS trigger
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


ALTER FUNCTION public.tr_createlog() OWNER TO dmitriy;

SET default_tablespace = '';

SET default_table_access_method = heap;

--
-- Name: campus; Type: TABLE; Schema: public; Owner: dmitriy
--

CREATE TABLE public.campus (
    id integer NOT NULL,
    name character varying(50) NOT NULL,
    adress character varying(50) NOT NULL,
    phone character varying(20) NOT NULL,
    workstart time without time zone NOT NULL,
    workend time without time zone NOT NULL
);


ALTER TABLE public.campus OWNER TO dmitriy;

--
-- Name: campus_id_seq; Type: SEQUENCE; Schema: public; Owner: dmitriy
--

CREATE SEQUENCE public.campus_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.campus_id_seq OWNER TO dmitriy;

--
-- Name: campus_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: dmitriy
--

ALTER SEQUENCE public.campus_id_seq OWNED BY public.campus.id;


--
-- Name: cathedra; Type: TABLE; Schema: public; Owner: dmitriy
--

CREATE TABLE public.cathedra (
    id integer NOT NULL,
    name character varying(50) NOT NULL,
    phone character varying(20) NOT NULL,
    email character varying(50) NOT NULL,
    faculty_id integer NOT NULL,
    campus_id integer NOT NULL,
    chief_id integer NOT NULL
);


ALTER TABLE public.cathedra OWNER TO dmitriy;

--
-- Name: cathedra_id_seq; Type: SEQUENCE; Schema: public; Owner: dmitriy
--

CREATE SEQUENCE public.cathedra_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.cathedra_id_seq OWNER TO dmitriy;

--
-- Name: cathedra_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: dmitriy
--

ALTER SEQUENCE public.cathedra_id_seq OWNED BY public.cathedra.id;


--
-- Name: group; Type: TABLE; Schema: public; Owner: dmitriy
--

CREATE TABLE public."group" (
    id integer NOT NULL,
    cipher character varying(50) NOT NULL,
    course integer NOT NULL,
    studentscount integer NOT NULL,
    cathedra_id integer NOT NULL,
    specialty_id integer NOT NULL
);


ALTER TABLE public."group" OWNER TO dmitriy;

--
-- Name: teacher; Type: TABLE; Schema: public; Owner: dmitriy
--

CREATE TABLE public.teacher (
    id integer NOT NULL,
    name character varying(50) NOT NULL,
    age integer NOT NULL,
    phone character varying(20) NOT NULL,
    email character varying(50) NOT NULL,
    cathedra_id integer NOT NULL,
    teacherprofile_id integer NOT NULL
);


ALTER TABLE public.teacher OWNER TO dmitriy;

--
-- Name: chiefbygroup; Type: VIEW; Schema: public; Owner: dmitriy
--

CREATE VIEW public.chiefbygroup AS
 SELECT "group".cipher,
    teacher.name
   FROM public."group",
    (public.teacher
     LEFT JOIN public.cathedra ON ((cathedra.chief_id = teacher.id)))
  WHERE ("group".cathedra_id = cathedra.id);


ALTER TABLE public.chiefbygroup OWNER TO dmitriy;

--
-- Name: classroom; Type: TABLE; Schema: public; Owner: dmitriy
--

CREATE TABLE public.classroom (
    id integer NOT NULL,
    name character varying(50) NOT NULL,
    campus_id integer NOT NULL
);


ALTER TABLE public.classroom OWNER TO dmitriy;

--
-- Name: classroom_id_seq; Type: SEQUENCE; Schema: public; Owner: dmitriy
--

CREATE SEQUENCE public.classroom_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.classroom_id_seq OWNER TO dmitriy;

--
-- Name: classroom_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: dmitriy
--

ALTER SEQUENCE public.classroom_id_seq OWNED BY public.classroom.id;


--
-- Name: classtime; Type: TABLE; Schema: public; Owner: dmitriy
--

CREATE TABLE public.classtime (
    id integer NOT NULL,
    starttime time without time zone NOT NULL,
    endtime time without time zone NOT NULL
);


ALTER TABLE public.classtime OWNER TO dmitriy;

--
-- Name: classtime_id_seq; Type: SEQUENCE; Schema: public; Owner: dmitriy
--

CREATE SEQUENCE public.classtime_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.classtime_id_seq OWNER TO dmitriy;

--
-- Name: classtime_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: dmitriy
--

ALTER SEQUENCE public.classtime_id_seq OWNED BY public.classtime.id;


--
-- Name: faculty; Type: TABLE; Schema: public; Owner: dmitriy
--

CREATE TABLE public.faculty (
    id integer NOT NULL,
    name character varying(50) NOT NULL,
    phone character varying(20) NOT NULL,
    email character varying(50) NOT NULL,
    chief_id integer NOT NULL,
    campus_id integer NOT NULL
);


ALTER TABLE public.faculty OWNER TO dmitriy;

--
-- Name: faculty_id_seq; Type: SEQUENCE; Schema: public; Owner: dmitriy
--

CREATE SEQUENCE public.faculty_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.faculty_id_seq OWNER TO dmitriy;

--
-- Name: faculty_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: dmitriy
--

ALTER SEQUENCE public.faculty_id_seq OWNED BY public.faculty.id;


--
-- Name: group_id_seq; Type: SEQUENCE; Schema: public; Owner: dmitriy
--

CREATE SEQUENCE public.group_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.group_id_seq OWNER TO dmitriy;

--
-- Name: group_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: dmitriy
--

ALTER SEQUENCE public.group_id_seq OWNED BY public."group".id;


--
-- Name: schedule; Type: TABLE; Schema: public; Owner: dmitriy
--

CREATE TABLE public.schedule (
    id integer NOT NULL,
    subject_id integer NOT NULL,
    group_id integer NOT NULL,
    teacher_id integer NOT NULL,
    classtype character varying(20) NOT NULL,
    classroom_id integer NOT NULL,
    classtime_id integer NOT NULL,
    weekday character varying(20) NOT NULL
);


ALTER TABLE public.schedule OWNER TO dmitriy;

--
-- Name: schedule_id_seq; Type: SEQUENCE; Schema: public; Owner: dmitriy
--

CREATE SEQUENCE public.schedule_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.schedule_id_seq OWNER TO dmitriy;

--
-- Name: schedule_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: dmitriy
--

ALTER SEQUENCE public.schedule_id_seq OWNED BY public.schedule.id;


--
-- Name: specialty; Type: TABLE; Schema: public; Owner: dmitriy
--

CREATE TABLE public.specialty (
    id integer NOT NULL,
    name character varying(50) NOT NULL,
    cipher character varying(10) NOT NULL
);


ALTER TABLE public.specialty OWNER TO dmitriy;

--
-- Name: specialty_id_seq; Type: SEQUENCE; Schema: public; Owner: dmitriy
--

CREATE SEQUENCE public.specialty_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.specialty_id_seq OWNER TO dmitriy;

--
-- Name: specialty_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: dmitriy
--

ALTER SEQUENCE public.specialty_id_seq OWNED BY public.specialty.id;


--
-- Name: subject; Type: TABLE; Schema: public; Owner: dmitriy
--

CREATE TABLE public.subject (
    id integer NOT NULL,
    name character varying(100) NOT NULL
);


ALTER TABLE public.subject OWNER TO dmitriy;

--
-- Name: subject_id_seq; Type: SEQUENCE; Schema: public; Owner: dmitriy
--

CREATE SEQUENCE public.subject_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.subject_id_seq OWNER TO dmitriy;

--
-- Name: subject_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: dmitriy
--

ALTER SEQUENCE public.subject_id_seq OWNED BY public.subject.id;


--
-- Name: teacher_id_seq; Type: SEQUENCE; Schema: public; Owner: dmitriy
--

CREATE SEQUENCE public.teacher_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.teacher_id_seq OWNER TO dmitriy;

--
-- Name: teacher_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: dmitriy
--

ALTER SEQUENCE public.teacher_id_seq OWNED BY public.teacher.id;


--
-- Name: teacherprofile; Type: TABLE; Schema: public; Owner: dmitriy
--

CREATE TABLE public.teacherprofile (
    id integer NOT NULL,
    rank character varying(50),
    grade character varying(50),
    "position" character varying(50) NOT NULL,
    education character varying(50) NOT NULL
);


ALTER TABLE public.teacherprofile OWNER TO dmitriy;

--
-- Name: teacherprofile_id_seq; Type: SEQUENCE; Schema: public; Owner: dmitriy
--

CREATE SEQUENCE public.teacherprofile_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.teacherprofile_id_seq OWNER TO dmitriy;

--
-- Name: teacherprofile_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: dmitriy
--

ALTER SEQUENCE public.teacherprofile_id_seq OWNED BY public.teacherprofile.id;


--
-- Name: teacherprofilelogs; Type: TABLE; Schema: public; Owner: dmitriy
--

CREATE TABLE public.teacherprofilelogs (
    id integer NOT NULL,
    msg character varying(255) NOT NULL,
    logtime time without time zone NOT NULL
);


ALTER TABLE public.teacherprofilelogs OWNER TO dmitriy;

--
-- Name: teacherprofilelogs_id_seq; Type: SEQUENCE; Schema: public; Owner: dmitriy
--

CREATE SEQUENCE public.teacherprofilelogs_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.teacherprofilelogs_id_seq OWNER TO dmitriy;

--
-- Name: teacherprofilelogs_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: dmitriy
--

ALTER SEQUENCE public.teacherprofilelogs_id_seq OWNED BY public.teacherprofilelogs.id;


--
-- Name: campus id; Type: DEFAULT; Schema: public; Owner: dmitriy
--

ALTER TABLE ONLY public.campus ALTER COLUMN id SET DEFAULT nextval('public.campus_id_seq'::regclass);


--
-- Name: cathedra id; Type: DEFAULT; Schema: public; Owner: dmitriy
--

ALTER TABLE ONLY public.cathedra ALTER COLUMN id SET DEFAULT nextval('public.cathedra_id_seq'::regclass);


--
-- Name: classroom id; Type: DEFAULT; Schema: public; Owner: dmitriy
--

ALTER TABLE ONLY public.classroom ALTER COLUMN id SET DEFAULT nextval('public.classroom_id_seq'::regclass);


--
-- Name: classtime id; Type: DEFAULT; Schema: public; Owner: dmitriy
--

ALTER TABLE ONLY public.classtime ALTER COLUMN id SET DEFAULT nextval('public.classtime_id_seq'::regclass);


--
-- Name: faculty id; Type: DEFAULT; Schema: public; Owner: dmitriy
--

ALTER TABLE ONLY public.faculty ALTER COLUMN id SET DEFAULT nextval('public.faculty_id_seq'::regclass);


--
-- Name: group id; Type: DEFAULT; Schema: public; Owner: dmitriy
--

ALTER TABLE ONLY public."group" ALTER COLUMN id SET DEFAULT nextval('public.group_id_seq'::regclass);


--
-- Name: schedule id; Type: DEFAULT; Schema: public; Owner: dmitriy
--

ALTER TABLE ONLY public.schedule ALTER COLUMN id SET DEFAULT nextval('public.schedule_id_seq'::regclass);


--
-- Name: specialty id; Type: DEFAULT; Schema: public; Owner: dmitriy
--

ALTER TABLE ONLY public.specialty ALTER COLUMN id SET DEFAULT nextval('public.specialty_id_seq'::regclass);


--
-- Name: subject id; Type: DEFAULT; Schema: public; Owner: dmitriy
--

ALTER TABLE ONLY public.subject ALTER COLUMN id SET DEFAULT nextval('public.subject_id_seq'::regclass);


--
-- Name: teacher id; Type: DEFAULT; Schema: public; Owner: dmitriy
--

ALTER TABLE ONLY public.teacher ALTER COLUMN id SET DEFAULT nextval('public.teacher_id_seq'::regclass);


--
-- Name: teacherprofile id; Type: DEFAULT; Schema: public; Owner: dmitriy
--

ALTER TABLE ONLY public.teacherprofile ALTER COLUMN id SET DEFAULT nextval('public.teacherprofile_id_seq'::regclass);


--
-- Name: teacherprofilelogs id; Type: DEFAULT; Schema: public; Owner: dmitriy
--

ALTER TABLE ONLY public.teacherprofilelogs ALTER COLUMN id SET DEFAULT nextval('public.teacherprofilelogs_id_seq'::regclass);


--
-- Data for Name: campus; Type: TABLE DATA; Schema: public; Owner: dmitriy
--

COPY public.campus (id, name, adress, phone, workstart, workend) FROM stdin;
1	Кампус на проспекте Вернадского 78	проспект Вернадского, 78	+7 (920) 380-22-11	09:00:00	23:00:00
2	Кампус на улице Стромынка	улица Стромынка, д. 20	+7 (930) 970-22-55	08:00:00	22:45:00
3	Кампус на проспекте Вернадского 86	проспект Вернадского, 86	+7 (920) 845-12-24	09:00:00	23:00:00
4	Кампус на улице Соколиная гора	5-я ул. Соколиной горы, дом 22	+7 (912) 345-90-80	09:00:00	22:30:00
5	Кампус на улице Малая Пироговская	улица Малая Пироговская, д. 1, стр. 5	+7 (955) 555-92-33	09:00:00	21:00:00
\.


--
-- Data for Name: cathedra; Type: TABLE DATA; Schema: public; Owner: dmitriy
--

COPY public.cathedra (id, name, phone, email, faculty_id, campus_id, chief_id) FROM stdin;
1	Кафедра Высшей Математики	+7 (933) 222-33-44	math@univer.ru	1	1	2
2	Кафедра Физики	+7 (933) 111-22-33	fizika@univer.ru	1	2	5
3	Кафедра Информационных технологий	+7 (933) 333-44-55	it@univer.ru	1	1	6
4	Кафедра Гуманитарных наук	+7 (933) 555-66-77	guman@univer.ru	2	3	8
5	Кафедра Информационной безопасности	+7 (933) 444-55-66	infobez@univer.ru	1	4	10
\.


--
-- Data for Name: classroom; Type: TABLE DATA; Schema: public; Owner: dmitriy
--

COPY public.classroom (id, name, campus_id) FROM stdin;
1	A-1	1
2	A-2	1
3	A-3	1
4	A-4	1
5	A-5	1
6	A-6	1
7	A-7	1
8	A-8	1
9	Б-132	1
10	Б-240	1
11	В-102	1
12	В-222	1
13	Г-188	1
14	Д-101	1
15	Е-250	1
16	128	2
17	216	2
18	249	2
19	309	2
20	330	2
21	426	2
22	451	2
23	К-1	3
24	К-2	3
25	У-112	3
26	У-200	3
27	Т-31	4
28	Т-23	4
29	22	5
30	18	5
\.


--
-- Data for Name: classtime; Type: TABLE DATA; Schema: public; Owner: dmitriy
--

COPY public.classtime (id, starttime, endtime) FROM stdin;
1	09:00:00	10:30:00
2	10:40:00	12:10:00
3	12:40:00	14:10:00
4	14:20:00	15:50:00
5	16:20:00	17:50:00
6	18:00:00	19:30:00
\.


--
-- Data for Name: faculty; Type: TABLE DATA; Schema: public; Owner: dmitriy
--

COPY public.faculty (id, name, phone, email, chief_id, campus_id) FROM stdin;
1	Технический	+7 (922) 390-15-69	fizmat@univer.ru	2	1
2	Гуманитарный	+7 (922) 401-26-70	gum@univer.ru	8	3
\.


--
-- Data for Name: group; Type: TABLE DATA; Schema: public; Owner: dmitriy
--

COPY public."group" (id, cipher, course, studentscount, cathedra_id, specialty_id) FROM stdin;
1	БСБО-01	3	30	3	5
2	БСБО-02	1	32	3	5
3	ККК-01	4	21	2	4
4	ФИБО-01	1	35	2	3
5	МЕХА-01	1	31	1	2
6	МАТАН-01	1	32	1	1
7	ИТТО-01	1	30	3	6
8	ИТТО-01	3	25	3	6
9	ФИЛО-01	2	33	4	7
10	ИНФБ-01	4	23	5	8
11	МАТАН-01	2	29	1	1
12	КЕК-00	5	19	3	5
\.


--
-- Data for Name: schedule; Type: TABLE DATA; Schema: public; Owner: dmitriy
--

COPY public.schedule (id, subject_id, group_id, teacher_id, classtype, classroom_id, classtime_id, weekday) FROM stdin;
1	5	1	9	Лекция	12	1	Понедельник
2	7	3	7	Лекция	28	1	Понедельник
3	1	1	1	Практика	22	1	Понедельник
4	5	2	9	Лекция	19	2	Понедельник
5	5	3	5	Практика	5	2	Понедельник
6	2	8	1	Лекция	6	3	Понедельник
7	8	8	8	Лекция	25	3	Понедельник
8	6	1	5	Лекция	4	3	Понедельник
9	5	4	9	Лекция	2	4	Понедельник
10	2	7	2	Практика	10	5	Понедельник
11	1	2	3	Практика	14	5	Понедельник
12	5	5	5	Практика	15	5	Понедельник
13	1	3	2	Лекция	1	6	Понедельник
14	1	4	3	Лекция	9	6	Понедельник
15	8	1	7	Лекция	18	1	Вторник
16	8	8	8	Практика	24	1	Вторник
17	6	2	5	Лекция	26	2	Вторник
18	5	6	5	Лекция	20	2	Вторник
19	5	7	9	Лекция	30	2	Вторник
20	3	1	1	Практика	23	3	Вторник
21	3	2	2	Лекция	17	3	Вторник
22	6	7	6	Лекция	13	4	Вторник
23	4	1	5	Лекция	11	4	Вторник
24	7	8	8	Практика	21	4	Вторник
25	2	6	3	Лекция	16	5	Вторник
26	7	7	8	Лекция	29	5	Вторник
27	1	5	4	Практика	8	5	Вторник
28	6	8	5	Лекция	7	1	Среда
29	4	2	6	Лабораторная работа	27	1	Среда
30	8	2	7	Практика	3	1	Среда
31	3	3	3	Лекция	11	2	Среда
32	1	6	1	Лекция	19	2	Среда
33	6	1	5	Практика	6	2	Среда
34	3	4	4	Лекция	3	3	Среда
35	5	1	9	Лекция	17	3	Среда
36	3	7	1	Практика	4	3	Среда
37	5	8	5	Лекция	28	4	Среда
38	5	10	6	Лекция	25	5	Среда
39	1	7	2	Практика	1	5	Среда
40	1	8	3	Лекция	20	5	Среда
41	6	2	6	Лекция	15	5	Среда
42	1	1	4	Лекция	14	1	Четверг
43	6	7	5	Практика	27	1	Четверг
44	7	8	8	Практика	8	2	Четверг
45	1	1	1	Лекция	29	2	Четверг
46	6	8	6	Практика	5	3	Четверг
47	6	1	5	Практика	30	3	Четверг
48	6	2	9	Лекция	24	3	Четверг
49	2	1	4	Практика	9	3	Четверг
50	2	2	1	Практика	16	4	Четверг
51	1	10	1	Лекция	7	4	Четверг
52	5	11	9	Практика	10	4	Четверг
53	8	8	7	Практика	26	4	Четверг
54	5	12	5	Лекция	13	4	Четверг
55	4	2	5	Лабораторная работа	12	5	Четверг
56	2	1	2	Лекция	7	1	Пятница
57	4	2	6	Лекция	22	1	Пятница
58	5	1	6	Лекция	21	2	Пятница
59	8	1	8	Лекция	23	2	Пятница
60	7	2	7	Лекция	2	2	Пятница
61	4	1	5	Практика	12	2	Пятница
62	2	2	1	Практика	22	3	Пятница
63	7	8	7	Лекция	18	3	Пятница
64	2	3	3	Лекция	20	3	Пятница
65	5	4	9	Лекция	16	3	Пятница
66	4	7	5	Практика	11	3	Пятница
67	5	2	5	Лекция	17	3	Пятница
68	1	11	2	Лекция	28	4	Пятница
69	1	2	4	Практика	6	4	Пятница
70	5	3	9	Лекция	12	4	Пятница
71	1	3	3	Лекция	2	5	Пятница
72	6	8	5	Лекция	26	1	Суббота
73	6	7	6	Лекция	14	1	Суббота
74	7	1	8	Лекция	19	1	Суббота
75	4	8	6	Лекция	13	1	Суббота
76	7	8	7	Лекция	9	2	Суббота
77	4	10	6	Практика	29	2	Суббота
78	2	4	4	Лекция	25	2	Суббота
79	6	1	6	Практика	3	2	Суббота
80	6	2	5	Практика	24	3	Суббота
81	4	1	6	Лабораторная работа	5	3	Суббота
82	8	8	8	Лекция	8	3	Суббота
83	1	12	1	Практика	21	4	Суббота
84	2	5	1	Лекция	18	4	Суббота
85	9	1	4	Лекция	30	4	Суббота
86	9	7	5	Практика	22	4	Суббота
87	9	5	6	Лекция	15	5	Суббота
88	9	2	4	Лекция	27	5	Суббота
89	9	8	5	Лекция	7	6	Суббота
90	9	6	4	Практика	10	6	Суббота
\.


--
-- Data for Name: specialty; Type: TABLE DATA; Schema: public; Owner: dmitriy
--

COPY public.specialty (id, name, cipher) FROM stdin;
1	Прикладная математика	1
2	Математика и механика	5
3	Прикладная физика	2
4	Астрономия	3
5	Прикладная информатика	4
6	Программная инженерия	6
7	Филология	7
8	Информационная безопасность	8
\.


--
-- Data for Name: subject; Type: TABLE DATA; Schema: public; Owner: dmitriy
--

COPY public.subject (id, name) FROM stdin;
1	Математический анализ
2	Линейная алгебра
3	Аналитическая геометрия
4	Языки программирования
5	Компьютерные сети
6	Базы данных
7	Философия
8	История
9	Операционные системы
\.


--
-- Data for Name: teacher; Type: TABLE DATA; Schema: public; Owner: dmitriy
--

COPY public.teacher (id, name, age, phone, email, cathedra_id, teacherprofile_id) FROM stdin;
1	Волков Георгий Ильич	51	+7 (911) 123-34-45	volkov@univer.ru	1	6
2	Баранова Анна Егоровна	65	+7 (911) 567-78-89	baranova@univer.ru	1	5
3	Кондратьева Злата Глебовна	26	+7 (911) 912-23-34	kondrateva@univer.ru	1	7
4	Ефремов Марк Даниилович	28	+7 (911) 456-67-78	efremov@univer.ru	1	2
5	Миронов Владимир Фёдорович	48	+7 (912) 123-34-45	mironov@univer.ru	2	8
6	Яковлев Герман Иванович	51	+7 (913) 123-34-45	yakovlev@univer.ru	3	8
7	Савельева Мила Максимовна	32	+7 (913) 567-78-89	saveleva@univer.ru	3	1
8	Леонова Алиса Николаевна	45	+7 (914) 123-34-45	leonova@univer.ru	4	4
9	Аксенов Платон Тимофеевич	31	+7 (914) 567-78-89	aksenov@univer.ru	4	3
10	Борисов Александр Владимирович	36	+7 (915) 123-34-45	borisov@univer.ru	5	5
\.


--
-- Data for Name: teacherprofile; Type: TABLE DATA; Schema: public; Owner: dmitriy
--

COPY public.teacherprofile (id, rank, grade, "position", education) FROM stdin;
1	Кандидат наук	Доцент	Преподаватель	Высшее физ-мат
2	Кандидат наук	Старший преподаватель	Преподаватель	Высшее физ-мат
3	Кандидат наук	Доцент	Преподаватель	Высшее филологическое
4	Доктор наук	Профессор	Зав. кафедрой	Высшее филологическое
5	Доктор наук	Профессор	Зав. кафедрой	Высшее физ-мат
6	Доктор наук	Профессор	Преподаватель	Высшее физ-мат
7	\N	\N	Преподаватель	Высшее физ-мат
8	Кандидат наук	Доцент	Зав. кафедрой	Высшее физ-мат
\.


--
-- Data for Name: teacherprofilelogs; Type: TABLE DATA; Schema: public; Owner: dmitriy
--

COPY public.teacherprofilelogs (id, msg, logtime) FROM stdin;
\.


--
-- Name: campus_id_seq; Type: SEQUENCE SET; Schema: public; Owner: dmitriy
--

SELECT pg_catalog.setval('public.campus_id_seq', 5, true);


--
-- Name: cathedra_id_seq; Type: SEQUENCE SET; Schema: public; Owner: dmitriy
--

SELECT pg_catalog.setval('public.cathedra_id_seq', 5, true);


--
-- Name: classroom_id_seq; Type: SEQUENCE SET; Schema: public; Owner: dmitriy
--

SELECT pg_catalog.setval('public.classroom_id_seq', 30, true);


--
-- Name: classtime_id_seq; Type: SEQUENCE SET; Schema: public; Owner: dmitriy
--

SELECT pg_catalog.setval('public.classtime_id_seq', 6, true);


--
-- Name: faculty_id_seq; Type: SEQUENCE SET; Schema: public; Owner: dmitriy
--

SELECT pg_catalog.setval('public.faculty_id_seq', 2, true);


--
-- Name: group_id_seq; Type: SEQUENCE SET; Schema: public; Owner: dmitriy
--

SELECT pg_catalog.setval('public.group_id_seq', 14, true);


--
-- Name: schedule_id_seq; Type: SEQUENCE SET; Schema: public; Owner: dmitriy
--

SELECT pg_catalog.setval('public.schedule_id_seq', 90, true);


--
-- Name: specialty_id_seq; Type: SEQUENCE SET; Schema: public; Owner: dmitriy
--

SELECT pg_catalog.setval('public.specialty_id_seq', 8, true);


--
-- Name: subject_id_seq; Type: SEQUENCE SET; Schema: public; Owner: dmitriy
--

SELECT pg_catalog.setval('public.subject_id_seq', 9, true);


--
-- Name: teacher_id_seq; Type: SEQUENCE SET; Schema: public; Owner: dmitriy
--

SELECT pg_catalog.setval('public.teacher_id_seq', 11, true);


--
-- Name: teacherprofile_id_seq; Type: SEQUENCE SET; Schema: public; Owner: dmitriy
--

SELECT pg_catalog.setval('public.teacherprofile_id_seq', 8, true);


--
-- Name: teacherprofilelogs_id_seq; Type: SEQUENCE SET; Schema: public; Owner: dmitriy
--

SELECT pg_catalog.setval('public.teacherprofilelogs_id_seq', 1, false);


--
-- Name: campus pk_campus; Type: CONSTRAINT; Schema: public; Owner: dmitriy
--

ALTER TABLE ONLY public.campus
    ADD CONSTRAINT pk_campus PRIMARY KEY (id);


--
-- Name: cathedra pk_cathedra; Type: CONSTRAINT; Schema: public; Owner: dmitriy
--

ALTER TABLE ONLY public.cathedra
    ADD CONSTRAINT pk_cathedra PRIMARY KEY (id);


--
-- Name: classtime pk_class; Type: CONSTRAINT; Schema: public; Owner: dmitriy
--

ALTER TABLE ONLY public.classtime
    ADD CONSTRAINT pk_class PRIMARY KEY (id);


--
-- Name: classroom pk_classroom; Type: CONSTRAINT; Schema: public; Owner: dmitriy
--

ALTER TABLE ONLY public.classroom
    ADD CONSTRAINT pk_classroom PRIMARY KEY (id);


--
-- Name: faculty pk_faculty; Type: CONSTRAINT; Schema: public; Owner: dmitriy
--

ALTER TABLE ONLY public.faculty
    ADD CONSTRAINT pk_faculty PRIMARY KEY (id);


--
-- Name: group pk_group; Type: CONSTRAINT; Schema: public; Owner: dmitriy
--

ALTER TABLE ONLY public."group"
    ADD CONSTRAINT pk_group PRIMARY KEY (id);


--
-- Name: schedule pk_schedule; Type: CONSTRAINT; Schema: public; Owner: dmitriy
--

ALTER TABLE ONLY public.schedule
    ADD CONSTRAINT pk_schedule PRIMARY KEY (id);


--
-- Name: specialty pk_specialty; Type: CONSTRAINT; Schema: public; Owner: dmitriy
--

ALTER TABLE ONLY public.specialty
    ADD CONSTRAINT pk_specialty PRIMARY KEY (id);


--
-- Name: subject pk_subject; Type: CONSTRAINT; Schema: public; Owner: dmitriy
--

ALTER TABLE ONLY public.subject
    ADD CONSTRAINT pk_subject PRIMARY KEY (id);


--
-- Name: teacher pk_teacher; Type: CONSTRAINT; Schema: public; Owner: dmitriy
--

ALTER TABLE ONLY public.teacher
    ADD CONSTRAINT pk_teacher PRIMARY KEY (id);


--
-- Name: teacherprofile pk_teacherprofile; Type: CONSTRAINT; Schema: public; Owner: dmitriy
--

ALTER TABLE ONLY public.teacherprofile
    ADD CONSTRAINT pk_teacherprofile PRIMARY KEY (id);


--
-- Name: teacherprofilelogs pk_teacherprofilelogs; Type: CONSTRAINT; Schema: public; Owner: dmitriy
--

ALTER TABLE ONLY public.teacherprofilelogs
    ADD CONSTRAINT pk_teacherprofilelogs PRIMARY KEY (id);


--
-- Name: campus_idindex; Type: INDEX; Schema: public; Owner: dmitriy
--

CREATE INDEX campus_idindex ON public.campus USING btree (name);


--
-- Name: cathedra_idindex; Type: INDEX; Schema: public; Owner: dmitriy
--

CREATE INDEX cathedra_idindex ON public.cathedra USING btree (phone);


--
-- Name: classroom_idindex; Type: INDEX; Schema: public; Owner: dmitriy
--

CREATE INDEX classroom_idindex ON public.classroom USING btree (name);


--
-- Name: faculty_idindex; Type: INDEX; Schema: public; Owner: dmitriy
--

CREATE INDEX faculty_idindex ON public.faculty USING btree (phone);


--
-- Name: group_idindex; Type: INDEX; Schema: public; Owner: dmitriy
--

CREATE INDEX group_idindex ON public."group" USING btree (cipher);


--
-- Name: schedule_idindex; Type: INDEX; Schema: public; Owner: dmitriy
--

CREATE INDEX schedule_idindex ON public.schedule USING btree (weekday);


--
-- Name: teacher_idindex; Type: INDEX; Schema: public; Owner: dmitriy
--

CREATE INDEX teacher_idindex ON public.teacher USING btree (name);


--
-- Name: teacherprofile tr_teacherprofile; Type: TRIGGER; Schema: public; Owner: dmitriy
--

CREATE TRIGGER tr_teacherprofile AFTER INSERT OR DELETE OR UPDATE ON public.teacherprofile FOR EACH ROW EXECUTE FUNCTION public.tr_createlog();


--
-- Name: cathedra fk_campustocathedra; Type: FK CONSTRAINT; Schema: public; Owner: dmitriy
--

ALTER TABLE ONLY public.cathedra
    ADD CONSTRAINT fk_campustocathedra FOREIGN KEY (campus_id) REFERENCES public.campus(id);


--
-- Name: classroom fk_campustoclassroom; Type: FK CONSTRAINT; Schema: public; Owner: dmitriy
--

ALTER TABLE ONLY public.classroom
    ADD CONSTRAINT fk_campustoclassroom FOREIGN KEY (campus_id) REFERENCES public.campus(id);


--
-- Name: faculty fk_campustofaculty; Type: FK CONSTRAINT; Schema: public; Owner: dmitriy
--

ALTER TABLE ONLY public.faculty
    ADD CONSTRAINT fk_campustofaculty FOREIGN KEY (campus_id) REFERENCES public.campus(id);


--
-- Name: teacher fk_cathedratoteacher; Type: FK CONSTRAINT; Schema: public; Owner: dmitriy
--

ALTER TABLE ONLY public.teacher
    ADD CONSTRAINT fk_cathedratoteacher FOREIGN KEY (cathedra_id) REFERENCES public.cathedra(id);


--
-- Name: cathedra fk_facultytocathedra; Type: FK CONSTRAINT; Schema: public; Owner: dmitriy
--

ALTER TABLE ONLY public.cathedra
    ADD CONSTRAINT fk_facultytocathedra FOREIGN KEY (faculty_id) REFERENCES public.faculty(id);


--
-- Name: group fk_grouptocathedra; Type: FK CONSTRAINT; Schema: public; Owner: dmitriy
--

ALTER TABLE ONLY public."group"
    ADD CONSTRAINT fk_grouptocathedra FOREIGN KEY (cathedra_id) REFERENCES public.cathedra(id);


--
-- Name: group fk_grouptospecialty; Type: FK CONSTRAINT; Schema: public; Owner: dmitriy
--

ALTER TABLE ONLY public."group"
    ADD CONSTRAINT fk_grouptospecialty FOREIGN KEY (specialty_id) REFERENCES public.specialty(id);


--
-- Name: schedule fk_scheduletoclassroom; Type: FK CONSTRAINT; Schema: public; Owner: dmitriy
--

ALTER TABLE ONLY public.schedule
    ADD CONSTRAINT fk_scheduletoclassroom FOREIGN KEY (classroom_id) REFERENCES public.classroom(id);


--
-- Name: schedule fk_scheduletoclasstime; Type: FK CONSTRAINT; Schema: public; Owner: dmitriy
--

ALTER TABLE ONLY public.schedule
    ADD CONSTRAINT fk_scheduletoclasstime FOREIGN KEY (classtime_id) REFERENCES public.classtime(id);


--
-- Name: schedule fk_scheduletogroup; Type: FK CONSTRAINT; Schema: public; Owner: dmitriy
--

ALTER TABLE ONLY public.schedule
    ADD CONSTRAINT fk_scheduletogroup FOREIGN KEY (group_id) REFERENCES public."group"(id);


--
-- Name: schedule fk_scheduletosubject; Type: FK CONSTRAINT; Schema: public; Owner: dmitriy
--

ALTER TABLE ONLY public.schedule
    ADD CONSTRAINT fk_scheduletosubject FOREIGN KEY (subject_id) REFERENCES public.subject(id);


--
-- Name: schedule fk_scheduletoteacher; Type: FK CONSTRAINT; Schema: public; Owner: dmitriy
--

ALTER TABLE ONLY public.schedule
    ADD CONSTRAINT fk_scheduletoteacher FOREIGN KEY (teacher_id) REFERENCES public.teacher(id);


--
-- Name: teacher fk_teacherprofiletoteacher; Type: FK CONSTRAINT; Schema: public; Owner: dmitriy
--

ALTER TABLE ONLY public.teacher
    ADD CONSTRAINT fk_teacherprofiletoteacher FOREIGN KEY (teacherprofile_id) REFERENCES public.teacherprofile(id);


--
-- Name: cathedra fk_teachertocathedra; Type: FK CONSTRAINT; Schema: public; Owner: dmitriy
--

ALTER TABLE ONLY public.cathedra
    ADD CONSTRAINT fk_teachertocathedra FOREIGN KEY (chief_id) REFERENCES public.teacher(id);


--
-- Name: faculty fk_teachertofaculty; Type: FK CONSTRAINT; Schema: public; Owner: dmitriy
--

ALTER TABLE ONLY public.faculty
    ADD CONSTRAINT fk_teachertofaculty FOREIGN KEY (chief_id) REFERENCES public.teacher(id);


--
-- PostgreSQL database dump complete
--

