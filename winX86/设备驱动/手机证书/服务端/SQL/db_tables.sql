
-- ----------------------------
-- Create a database
-- ----------------------------
CREATE DATABASE dbNetcaSoftwareDeviceServer CHARACTER SET utf8;
USE dbNetcaSoftwareDeviceServer;
SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for app_privkey
-- ----------------------------
DROP TABLE IF EXISTS `app_privkey`;
CREATE TABLE `app_privkey` (
  `id` bigint(20) unsigned NOT NULL AUTO_INCREMENT,
  `app_kid` varchar(64) NOT NULL,
  `d2` blob NOT NULL,
  `gmt_create` datetime NOT NULL,
  `gmt_modified` datetime NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `idx_app_kid` (`app_kid`) USING BTREE
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=COMPACT;

-- ----------------------------
-- Table structure for app_publickey
-- ----------------------------
DROP TABLE IF EXISTS `app_publickey`;
CREATE TABLE `app_publickey` (
  `id` bigint(20) unsigned NOT NULL AUTO_INCREMENT,
  `device_register_kid` varchar(64) NOT NULL,
  `app_kid` varchar(64) NOT NULL,
  `kty` char(20) DEFAULT NULL,
  `crv` char(20) DEFAULT NULL,
  `x` varchar(255) DEFAULT NULL,
  `y` varchar(255) DEFAULT NULL,
  `gmt_create` datetime NOT NULL,
  `gmt_modified` datetime NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `idx_app_kid` (`app_kid`) USING BTREE,
  KEY `idx_device_register_kid` (`device_register_kid`) USING BTREE
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=COMPACT;

-- ----------------------------
-- Table structure for app_use_recode
-- ----------------------------
DROP TABLE IF EXISTS `app_use_recode`;
CREATE TABLE `app_use_recode` (
  `id` bigint(20) unsigned NOT NULL AUTO_INCREMENT,
  `gmt_create` datetime NOT NULL,
  `gmt_modified` datetime NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=COMPACT;

-- ----------------------------
-- Table structure for device_operate_recode
-- ----------------------------
DROP TABLE IF EXISTS `device_operate_recode`;
CREATE TABLE `device_operate_recode` (
  `id` bigint(20) unsigned NOT NULL AUTO_INCREMENT,
  `gmt_create` datetime NOT NULL,
  `gmt_modified` datetime NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=COMPACT;

-- ----------------------------
-- Table structure for device_register_publickey
-- ----------------------------
DROP TABLE IF EXISTS `device_register_publickey`;
CREATE TABLE `device_register_publickey` (
  `id` bigint(20) unsigned NOT NULL AUTO_INCREMENT,
  `device_register_kid` varchar(64) NOT NULL,
  `kty` char(20) DEFAULT NULL,
  `crv` char(20) DEFAULT NULL,
  `x` varchar(255) DEFAULT NULL,
  `y` varchar(255) DEFAULT NULL,
  `gmt_create` datetime NOT NULL,
  `gmt_modified` datetime NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `idx_device_register_kid` (`device_register_kid`) USING BTREE
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=COMPACT;

-- ----------------------------
-- Table structure for enc_sub_privkey
-- ----------------------------
DROP TABLE IF EXISTS `enc_sub_privkey`;
CREATE TABLE `enc_sub_privkey` (
  `id` bigint(20) unsigned NOT NULL AUTO_INCREMENT,
  `device_register_kid` varchar(64) DEFAULT NULL,
  `enc_sub_kid` varchar(64) DEFAULT NULL,
  `sub_privkey` text,
  `gmt_create` datetime NOT NULL,
  `gmt_modified` datetime NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `idx_enc_sub_kid_device_register_kid` (`enc_sub_kid`,`device_register_kid`) USING BTREE
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=COMPACT;

-- ----------------------------
-- Table structure for interface_log
-- ----------------------------
DROP TABLE IF EXISTS `interface_log`;
CREATE TABLE `interface_log` (
  `id` bigint(20) unsigned NOT NULL AUTO_INCREMENT COMMENT '主键，递增',
  `name` varchar(32) DEFAULT NULL COMMENT '接口名称',
  `ip` varchar(64) DEFAULT NULL COMMENT '请求ip',
  `request_signature` text,
  `request_payLoad` text COMMENT '请求信息',
  `response_msg` text COMMENT '响应信息',
  `response_code` int(11) DEFAULT NULL COMMENT '响应码',
  `start_time` datetime DEFAULT NULL COMMENT '接口开始时间',
  `end_time` datetime DEFAULT NULL COMMENT '接口结束时间',
  `http_code` int(11) DEFAULT NULL COMMENT 'http响应状态码',
  `memo` text COMMENT '备注，失败时包含异常信息',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='应用服务接口日志表';

-- ----------------------------
-- Table structure for mobile_code
-- ----------------------------
DROP TABLE IF EXISTS `mobile_code`;
CREATE TABLE `mobile_code` (
  `id` bigint(20) unsigned NOT NULL AUTO_INCREMENT,
  `req_no` varchar(64) NOT NULL,
  `phone_no` char(20) DEFAULT NULL,
  `validity_code` char(6) DEFAULT NULL,
  `validity_period` int(11) DEFAULT NULL,
  `hmac_algo` char(10) DEFAULT NULL,
  `device_register_publickey_hash` varchar(255) NOT NULL,
  `publickey_hash_algo` char(10) NOT NULL,
  `gmt_create` datetime NOT NULL,
  `gmt_modified` datetime NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=COMPACT;

-- ----------------------------
-- Table structure for sms_log
-- ----------------------------
DROP TABLE IF EXISTS `sms_log`;
CREATE TABLE `sms_log` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `sms_mode` tinyint(3) unsigned NOT NULL,
  `sms_uri` varchar(512) NOT NULL,
  `type` int(10) unsigned NOT NULL,
  `gmt_create` datetime NOT NULL,
  `gmt_modified` datetime NOT NULL,
  `status` tinyint(2) unsigned DEFAULT NULL,
  `phone` varchar(64) NOT NULL,
  `content` text,
  `resp_msg` text,
  `memo` text,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for system_config
-- ----------------------------
DROP TABLE IF EXISTS `system_config`;
CREATE TABLE `system_config` (
  `id` bigint(20) unsigned NOT NULL AUTO_INCREMENT,
  `type` tinyint(2) DEFAULT NULL COMMENT '1为签名相关配置项',
  `name` varchar(64) DEFAULT NULL,
  `key` varchar(64) NOT NULL,
  `value` text,
  `gmt_create` datetime NOT NULL,
  `gmt_modified` datetime NOT NULL,
  `description` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `key` (`key`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=COMPACT;

-- ----------------------------
-- Create user
-- ----------------------------
CREATE USER duNetcaSoftwareDeviceServer@'%' IDENTIFIED BY 'CAZm5MdAK678';
GRANT select, insert ON dbNetcaSoftwareDeviceServer.* TO duNetcaSoftwareDeviceServer@'%';
GRANT update, delete ON dbNetcaSoftwareDeviceServer.app_privkey TO duNetcaSoftwareDeviceServer@'%';
GRANT update, delete ON dbNetcaSoftwareDeviceServer.app_publickey TO duNetcaSoftwareDeviceServer@'%';
GRANT update, delete ON dbNetcaSoftwareDeviceServer.app_use_recode TO duNetcaSoftwareDeviceServer@'%';
GRANT update, delete ON dbNetcaSoftwareDeviceServer.device_operate_recode TO duNetcaSoftwareDeviceServer@'%';
GRANT update, delete ON dbNetcaSoftwareDeviceServer.device_register_publickey TO duNetcaSoftwareDeviceServer@'%';
GRANT update, delete ON dbNetcaSoftwareDeviceServer.enc_sub_privkey TO duNetcaSoftwareDeviceServer@'%';
GRANT update, delete ON dbNetcaSoftwareDeviceServer.interface_log TO duNetcaSoftwareDeviceServer@'%';
GRANT update, delete ON dbNetcaSoftwareDeviceServer.mobile_code TO duNetcaSoftwareDeviceServer@'%';
GRANT update, delete ON dbNetcaSoftwareDeviceServer.sms_log TO duNetcaSoftwareDeviceServer@'%';
GRANT update, delete ON dbNetcaSoftwareDeviceServer.system_config TO duNetcaSoftwareDeviceServer@'%';


CREATE USER duNetcaSoftwareDeviceServer@localhost IDENTIFIED BY 'CAZm5MdAK678';
GRANT select, insert ON dbNetcaSoftwareDeviceServer.* TO duNetcaSoftwareDeviceServer@localhost;
GRANT update, delete ON dbNetcaSoftwareDeviceServer.app_privkey TO duNetcaSoftwareDeviceServer@localhost;
GRANT update, delete ON dbNetcaSoftwareDeviceServer.app_publickey TO duNetcaSoftwareDeviceServer@localhost;
GRANT update, delete ON dbNetcaSoftwareDeviceServer.app_use_recode TO duNetcaSoftwareDeviceServer@localhost;
GRANT update, delete ON dbNetcaSoftwareDeviceServer.device_operate_recode TO duNetcaSoftwareDeviceServer@localhost;
GRANT update, delete ON dbNetcaSoftwareDeviceServer.device_register_publickey TO duNetcaSoftwareDeviceServer@localhost;
GRANT update, delete ON dbNetcaSoftwareDeviceServer.enc_sub_privkey TO duNetcaSoftwareDeviceServer@localhost;
GRANT update, delete ON dbNetcaSoftwareDeviceServer.interface_log TO duNetcaSoftwareDeviceServer@localhost;
GRANT update, delete ON dbNetcaSoftwareDeviceServer.mobile_code TO duNetcaSoftwareDeviceServer@localhost;
GRANT update, delete ON dbNetcaSoftwareDeviceServer.sms_log TO duNetcaSoftwareDeviceServer@localhost;
GRANT update, delete ON dbNetcaSoftwareDeviceServer.system_config TO duNetcaSoftwareDeviceServer@localhost;

FLUSH PRIVILEGES;