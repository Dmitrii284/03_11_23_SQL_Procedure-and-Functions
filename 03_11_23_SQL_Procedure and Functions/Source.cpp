/*
� SQL PL (SQL Procedural Language) ���� ��� �������� ��������: ��������� � �������.

�������� ������� ��������� �� ������� ����������� � ���, ��� ��������� ��������� ����� ������,
� ������� ���������� ��������.

��������� ����� ������������ ��� ���������� ������� �������� ��� ��������� ������. ��������,
��������� ����� �������������� ��� �������,
���������� ��� �������� ������ �� �������.

�������, � ������ �������, ������������ ��� ��������� ����������� �������� �� ������. ��������,
������� ����� ���� ������������ ��� �������� ���������� ������� � �������, ���������� �������� �������� ��� 
��������� ������ �� ������������� �������.

� �����, ��������� � ������� � SQL PL ��������� ��������� ��������� �������� � �������,
����� SQL ����� ������ � ������ ������.

������� �������� � ������� � SQL PL:

��������� ��� ������� ������ � �������:

CREATE PROCEDURE insert_data(IN p_name VARCHAR(50), IN p_age INT)
BEGIN
    INSERT INTO users (name, age) VALUES (p_name, p_age);
END;
��� ��������� ��������� ��� ��������� (��� � �������) � ��������� ����� ������ � ������� users.

������� ��� �������� ���������� ������� � �������:

CREATE FUNCTION count_users() RETURNS INT
BEGIN
    RETURN (SELECT COUNT(*) FROM users);
END;
��� ������� ���������� ���������� ������� � ������� users.

���������:

� � ����� ������� �� ���������� �������� ����� CREATE PROCEDURE � CREATE FUNCTION ��� 
�������� ����� �������� (��������� ��� �������).
� ����� ��������� ����� RETURNS ����������� ��� ������������� ��������. 
� ������ ������� count_users() ��� INT,
�� ���� ������� ���������� ����� �����.
� ������ ������� ��� ��������� ������������ SQL-������� ��� ������ � �������. � ������� count_users(),
��������, 
������������ ������ SELECT COUNT(*) FROM users ��� �������� ������� � �������.

\\\\\\\\\\\\\\\\\\\\\\\
PROCEDURE
\\\\\\\\\\\\\\\\\

��� �������� ��������� ���������� ������� � ����������� �� �������� >15000 �� ������ ��������� �������, �� ������ ������������ ��������� SQL-���:

USE hospital1
GO
CREATE PROCEDURE AddDoctor
    @name nvarchar(50),
    @surname nvarchar(50),
    @salary money,
    @premium money
AS
BEGIN
    INSERT INTO doctors (name, surname, salary, premium)
    VALUES (@name, @surname, @salary, @premium)
    WHERE salary > 15000
END
GO


��������� AddDoctor ��������� ��������� @name (���), @surname (�������),
@salary (��������) � @premium (������). ��� ��������� ����� ������ � ������� doctors,
������ ���� �������� �������� ��������� 15000.

�� ������ ������� ��������� � ������� ���������� ����:

EXEC AddDoctor '����', '������', 20000, 5000


���� ��� ������� ������ ������� � ������ "����", �������� "������", ��������� 20000 � ������� 5000,
��� ��� ��� �������� ��������� 15000.
\\\\\\\\\\\\\\\\\\\\\\\
FUNCTION
\\\\\\\\\\\\\\\\\
��� �������� ������� ������� ����� ���������� ����� � ���� �������� � ������� ������ 35%,
����� ������������ ��������� SQL-������:

USE [hospital1]
GO

CREATE FUNCTION dbo.CalculateNetSalary (@salary money, @premium money)
RETURNS money
AS
BEGIN
    DECLARE @netSalary money;
    SET @netSalary = (@salary + @premium) * (1 - 0.35);

    RETURN @netSalary;
END
GO


����� ���������� ������� �������, ����� ������� ������� dbo.CalculateNetSalary,
������� ��������� �������� (salary) � ������ (premium) 
������� � ���������� ���� ���������� ����� � ������� ������ 35%.

...........................
� SQL DECLARE ��� ������?
..................
� SQL PL, ���� ���������������� ��� ������ � ������ ������, 
DECLARE ������������ ��� ���������� ����������. ��������:

DECLARE
  var_name data_type [NOT NULL];
  var2 data_type2 [NOT NULL];
BEGIN
  -- statements
END;
����� �� ��������� ��� ���������� - var_name � var2.
��� ������ ���������� ����������� �� ���, ��� ������ � ����������� ���� NOT NULL, ������� ���������,
��� ���������� �� ������ ��������� null-��������.
����� ���������� ���������� ����� ������������ �� � SQL-�������� ��� ��������� � ���� ������ ��������.

\\\\\\\
������������� ��������� ������� � ��������� ���� 
\\\\\\\\\\\\\\
����� ������������ ������ ������� � SQL, �� ������ �������� �� � ������� SELECT ��������� �������:

SELECT *
FROM dbo.ret_table('John,Anna,Michael')


� ���� ������� �� �������� ������ "John,Anna,Michael" � �������� 
��������� @names ������� ret_table(). ������� STRING_SPLIT() ��������� ��� ������ �� ��������� ��������, 
�.�. "John", "Anna" � "Michael". ����� ������� ret_table() ���������� ������� �� �������� names, 
���������� ��� ��������:

names
------
John
Anna
Michael


�� ������ �������� �������� @names � �������� ����� ������ � �������, ������������ ��������.
����������� ����� ������� � ������������ ���������� � ������� names.

USE [hospital1]
GO

CREATE FUNCTION ret_table
(
  @names nvarchar(max)
)
RETURNS table
AS
RETURN
(
SELECT value AS names
FROM STRING_SPLIT(@Names, ',')
);


DECLARE @value NVARCHAR(max) ='DFG, ASG, TTTTTT, 3654654'
SELECT names
FROM dbo.ret_table(@value)

*/