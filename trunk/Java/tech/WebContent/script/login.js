function showLogon() {
	var div = document.createElement("div");
	// div.innerHTML="This is logon page";
	div.id = "signindiv";
	ShowDom(div, "登录", 310, 160);
	$("#signindiv").load("component/login.html");
}
function logout() {
	$
			.ajax({
				url : "account/logout",
				type : "post",
				dataType : "json",
				data : {},
				success : function(data) {
					if (data.status == "succeed") {
						$("#signin")
								.html(
										"<a href=\"javascript:void(0);\" onclick=\"javascript:showLogon();\">登陆</a>");
						$("#register")
								.html(
										"<a href=\"javascript:void(0);\" onclick=\"javascript:void(0);\">注册</a>");
					}
				}
			});
}
function login(username, userpwd, remember) {
	$.ajax({
		url : "login",
		type : "post",
		dataType : "json",
		data : {
			userName : username,
			userPwd : userpwd,
			remember : remember
		},
		beforeSend : function() {
			showProgress("正在登录，请稍等....");
			try {
				CloseDialog();
			} catch (e) {

			}
		},
		success : function(data) {
			if (data.status == "succeed") {
				showProgress("登录成功", function() {
					window.setTimeout(function() {
						hideProgress();
					}, 1000);
				});
				$("#register").html("");
				$("#signin").html(data.model.userNickName);
				var a = document.createElement("a");
				a.href = "javascript:void(0)";
				a.onclick = logout;
				a.innerHTML = "注销";
				$("#register").append(a);
				// install user data here
				addData("userId", data.userId);
				addData("userName", data.userName);
				addData("userNickName", data.userNickName);
				addData("userCompetence", data.userCompetence);
				addData("userLogonName", data.userLogonName);
				addData("userAvatarPath", data.userAvatarPath);
			}
		}
	});
}
function initpage() {
	var username = getCookie("name");
	var userpwd = getCookie("key");
	if (username != null && username != "" && userpwd != null && userpwd != "") {
		login(username, userpwd, "");
	}
	// 右键菜单 test
	// $("#footer").bind("mouseup",{},showMenu);
	var div = document.getElementById("left");
	// div.oncontextmenu=showMenu1;
}