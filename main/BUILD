load("@rules_cc//cc:defs.bzl", "cc_library", "cc_binary")

cc_library(
    name = "image",
    srcs = ["image.c"],
    hdrs = ["image.h"],
    deps = ["//lib:utils"],
)

cc_binary(
    name = "main",
    srcs = ["main.c"],
    deps = [
        ":image",
    ],
)