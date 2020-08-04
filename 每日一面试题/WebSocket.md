## WebSocket

1. **背景/应用场景**：消息推送/订阅发布模型
2. **典型用法**：
   * 客户端 JS：onopen，onclose，onerror，onmessage，send
   * Java：onOpen，onClose，onError，onMessage，sendText

3. **webSocket建立连接过程**

   HTTP出发，header带有connection和upgrade字段，尝试和服务器协商升级，如果对方同意，将返回一个101状态码的响应

