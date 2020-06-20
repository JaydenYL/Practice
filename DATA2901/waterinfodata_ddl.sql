-- Schema
-- NOTE: the schema of this dataset here follows the Option2 mapping as discussed in Wk3
--
--CREATE TABLE Measurements (stationid, obsdate, sensor, obsvalue)
--CREATE TABLE Stations (stationid, sitename, commence, cease, orga)
--CREATE TABLE Sensors (sensor, description, metric)
--CREATE TABLE Organisations (code, organisation)

-- pgplSQL simple --
CREATE SCHEMA WaterInfo;

SET search_path to WaterInfo;

CREATE TABLE Organisations (
	code         CHAR(3)     PRIMARY KEY,
	organisation VARCHAR(80)
);
CREATE TABLE Stations (
	stationid INT         PRIMARY KEY,
	sitename  VARCHAR(40) NOT NULL,
	commence  DATE,
	cease     DATE,
	orga      CHAR(3) REFERENCES Organisations(code)
);
CREATE TABLE Sensors (
	sensor      VARCHAR(6) PRIMARY KEY,
	description TEXT,
	metric      TEXT
);
CREATE TABLE Measurements (
	stationid INT        REFERENCES Stations(stationid),
	obsdate   DATE,
	sensor    VARCHAR(6) REFERENCES Sensors(sensor),
	obsvalue  NUMERIC,
	PRIMARY KEY (stationid, obsdate, sensor)
);
