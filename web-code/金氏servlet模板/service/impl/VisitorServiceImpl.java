package com.itpainter.service.impl;

import com.itpainter.dao.VisitorDao;
import com.itpainter.dao.impl.VisitorDaoImpl;
import com.itpainter.service.VisitorService;

public class VisitorServiceImpl implements VisitorService {
    private VisitorDao dao = new VisitorDaoImpl();
}
