package com.itpainter.dao.impl;

import com.itpainter.dao.VisitorDao;
import com.itpainter.util.JDBCUtils;
import org.springframework.jdbc.core.JdbcTemplate;

public class VisitorDaoImpl implements VisitorDao {
    private JdbcTemplate template = new JdbcTemplate(JDBCUtils.getDataSource());
}
