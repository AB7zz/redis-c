# MyRedis

A simple Redis clone implemented in C.

# How to run
```
make
make run-server
make run-client
```

# Redis Clone Implementation Checklist

## Data Types
- [ ] In-memory Key-Value Store
  - [ ] Strings (SET/GET)
  - [ ] Lists (LPUSH/RPUSH/LPOP/RPOP)
  - [ ] Sets (SADD/SREM/SMEMBERS)
  - [ ] Sorted Sets (ZADD/ZREM/ZRANGE)
  - [ ] Hashes (HSET/HGET/HDEL)
  - [ ] Streams (XADD/XREAD)

## Persistence
- [ ] Snapshot Persistence (SAVE/BGSAVE)
- [ ] Append-only File Persistence (AOF)

## Features
- [ ] TTL Support (EXPIRE/TTL)
- [ ] Pub/Sub Messaging (PUBLISH/SUBSCRIBE)
- [x] Client/Server Architecture
  - [x] TCP Socket Implementation
  - [x] Command Processing
  - [x] Response Formatting
- [ ] Event Loop for I/O Multiplexing
- [x] Single-threaded Architecture
- [ ] Atomic Operations
  - [ ] INCR
  - [ ] INCRBY
  - [ ] DECR
  - [ ] DECRBY