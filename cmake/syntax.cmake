find_package(RAGEL REQUIRED)
find_package(FLEX  REQUIRED)
find_package(BISON REQUIRED)

set(RAGEL_EXECUTABLE_opts -C -G2 )

# foreach(RAGEL_FILE ${RL})
#     string(REGEX REPLACE ".+\/(.+)\.ragel$" "${CMAKE_CURRENT_SOURCE_DIR}/\\1.ragel.cpp"
#                             PARSER_FILE ${RAGEL_FILE})
#     list(APPEND CP          ${PARSER_FILE})
#     add_custom_command(
#         OUTPUT              ${CMAKE_SOURCE_DIR}/${PARSER_FILE}
#         DEPENDS             ${RAGEL_FILE}
#         WORKING_DIRECTORY   ${CMAKE_SOURCE_DIR}
#         COMMAND             ${RAGEL_EXECUTABLE}
#         ARGS                ${RAGEL_EXECUTABLE_opts} -o ${PARSER_FILE} ${RAGEL_FILE}
#     )
# endforeach()

# foreach(LEX_FILE ${L})
#     string(REGEX REPLACE ".+\/(.+)\.lex$" "tmp/\\1.lex.cpp"
#                             PARSER_FILE ${LEX_FILE})
#     list(APPEND CP          ${PARSER_FILE})
#     add_custom_command(
#         OUTPUT              ${CMAKE_SOURCE_DIR}/${PARSER_FILE}
#         DEPENDS             ${LEX_FILE}
#         WORKING_DIRECTORY   ${CMAKE_SOURCE_DIR}
#         COMMAND             ${FLEX_EXECUTABLE}
#         ARGS                -o ${PARSER_FILE} ${LEX_FILE}
#     )
# endforeach()

foreach(YACC_FILE ${Y})
    cmake_path(REPLACE_EXTENSION
        YACC_FILE LAST_ONLY ".yacc.cpp"
        OUTPUT_VARIABLE PARSER_FILE)
    message("-- | " ${YACC_FILE} " " ${PARSER_FILE})
#     string(REGEX REPLACE ".+\/(.+)\.yacc$" "${CMAKE_CURRENT_SOURCE_DIR}/\\1.yacc.cpp"
#                             PARSER_FILE ${YACC_FILE})
#     list(APPEND CP          ${PARSER_FILE})
#     add_custom_command(
#         OUTPUT              ${CMAKE_SOURCE_DIR}/${PARSER_FILE}
#         DEPENDS             ${YACC_FILE}
#         WORKING_DIRECTORY   ${CMAKE_SOURCE_DIR}
#         COMMAND             ${BISON_EXECUTABLE}
#         ARGS                -o ${PARSER_FILE} ${YACC_FILE}
#     )
endforeach()
