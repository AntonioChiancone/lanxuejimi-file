package com.trnnn.orm;

import java.sql.Connection;
import java.util.Map;

public class ORMFactory {

	ActionFilter actionFilter;
	ORMModelPool modelPool;
	SQLExecutor executor;
	SQLQueryGenerator generator;
	Connection connection;

	public ORMFactory(Connection conn) {
		this.connection = conn;
		actionFilter = new ActionFilter();
		modelPool = new ORMModelPool();
		generator = new SQLQueryGenerator(modelPool);
		executor = new SQLExecutor(connection);
	}

	public void execute(Map<String, Object> values) {
		Action action = actionFilter.parse(values);
		String sql = this.generator.generate(action);
		this.executor.execute(sql);
	}
}
