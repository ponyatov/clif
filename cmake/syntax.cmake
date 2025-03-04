find_package(RAGEL REQUIRED)
find_package(FLEX  REQUIRED)
find_package(BISON REQUIRED)

set(RAGEL_EXECUTABLE_opts -C -G2 )

# foreach(RAGEL_FILE ${RL})
#     string(REGEX REPLACE ".+\/(.+)\.ragel$" "${CMAKE_CURRENT_SOURCE_DIR}/\\1.ragel.cpp"
#                             PARSER_CPP ${RAGEL_FILE})
#     list(APPEND CP          ${PARSER_CPP})
#     add_custom_command(
#         OUTPUT              ${CMAKE_SOURCE_DIR}/${PARSER_CPP}
#         DEPENDS             ${RAGEL_FILE}
#         WORKING_DIRECTORY   ${CMAKE_SOURCE_DIR}
#         COMMAND             ${RAGEL_EXECUTABLE}
#         ARGS                ${RAGEL_EXECUTABLE_opts} -o ${PARSER_CPP} ${RAGEL_FILE}
#     )
# endforeach()

# foreach(LEX_FILE ${L})
#     string(REGEX REPLACE ".+\/(.+)\.lex$" "tmp/\\1.lex.cpp"
#                             PARSER_CPP ${LEX_FILE})
#     list(APPEND CP          ${PARSER_CPP})
#     add_custom_command(
#         OUTPUT              ${CMAKE_SOURCE_DIR}/${PARSER_CPP}
#         DEPENDS             ${LEX_FILE}
#         WORKING_DIRECTORY   ${CMAKE_SOURCE_DIR}
#         COMMAND             ${FLEX_EXECUTABLE}
#         ARGS                -o ${PARSER_CPP} ${LEX_FILE}
#     )
# endforeach()

foreach(YACC_FILE ${Y})
    string(REGEX REPLACE ".+\/(.+)\.yacc$" "${CMAKE_BINARY_DIR}/\\1.yacc.cpp"
        PARSER_CPP ${YACC_FILE})
    string(REGEX REPLACE ".+\/(.+)\.yacc$" "${CMAKE_BINARY_DIR}/\\1.yacc.hpp"
        PARSER_HPP ${YACC_FILE})
    message("-- | " ${YACC_FILE} " " ${PARSER_CPP})
    list(APPEND CP          ${PARSER_CPP})
    list(APPEND HP          ${PARSER_HPP})
    add_custom_command(
        OUTPUT              ${PARSER_CPP} ${PARSER_HPP}
        DEPENDS             ${YACC_FILE}
        WORKING_DIRECTORY   ${CMAKE_SOURCE_DIR}
        COMMAND             ${BISON_EXECUTABLE}
        ARGS                -o ${PARSER_CPP} ${YACC_FILE}
    )
endforeach()
